#include "CSGTree.h"


CSGTree::CSGTree(CSGTree* leftChildTree, CSGTree* rightChildTree, booleanOperation operation) {
	this->leftChildTree = leftChildTree;
	this->rightChildTree = rightChildTree;
	this->operation = operation;
	this->isPrimitive = false;
	this->primitive = nullptr;
	this->geoOP = nullptr;
};

CSGTree::CSGTree(CSGTree* leftChildTree, GeometricOperation* geoOP, booleanOperation operation) {
	this->leftChildTree = leftChildTree;
	this->rightChildTree = nullptr;
	this->operation = operation;
	this->isPrimitive = false;
	this->primitive = nullptr;
	this->geoOP = geoOP;
}

CSGTree::CSGTree(Primitive* primitive) {
	this->leftChildTree = nullptr;
	this->rightChildTree = nullptr;
	this->operation = booleanOperation::NONE;
	this->isPrimitive = true;
	this->primitive = primitive;
	this->geoOP = nullptr;
};


std::vector<EdgeHits> CSGTree::checkIntersection(CSGRay r) {
	std::vector<EdgeHits> hits;

	if (this->isPrimitive) {
		return this->primitive->checkIntersection(r);
	}

	std::vector<EdgeHits> leftHits = leftChildTree->checkIntersection(r);
	std::vector<EdgeHits> rightHits = rightChildTree->checkIntersection(r);


	if (this->operation == booleanOperation::UNION) {
		//sempre remover a última entrada quando existem duas entradas seguidas
		int i = 0, j = 0;

		if (leftHits.size() == 0)
			return rightHits;
		if (rightHits.size() == 0)
			return leftHits;

		while ((i + j) < (int)(leftHits.size() + rightHits.size())) {
			int flag1 = 0, flag2 = 0;
			if (j == leftHits.size()) {
				flag1 = 1;
				j--;
			}
			if (i == rightHits.size()) {
				flag2 = 1;
				i--;
			}

			if (flag1 == 1) {
				hits.push_back(rightHits[i]);
				i++;
			}
			else if (flag2 == 1) {
				hits.push_back(leftHits[j]);
				j++;
			}

			else {
				if (rightHits[i].hitDistance < leftHits[j].hitDistance) {
					if (!hits.empty()) {
						if (hits.back().isEntry) {
							if (rightHits[i].isEntry) {
								i++;
								continue;
							}
							else {
								hits.push_back(rightHits[i]);
								i++;
							}
						}
						else {
							if (leftHits[j].isEntry || !rightHits[i].isEntry) {
								hits.push_back(rightHits[i]); 
								i++;
							}
							else i++;
						}
					}
					else {
						hits.push_back(rightHits[i]);
						i++;
					}
				}

				else {
					if (!hits.empty()) {
						if (hits.back().isEntry) {
							if (leftHits[j].isEntry) {
								j++;
								continue;
							}
							else {
								hits.push_back(leftHits[j]);
								j++;
							}
						}
						else {
							if (rightHits[i].isEntry || !leftHits[j].isEntry) {
								hits.push_back(leftHits[j]);
								j++;
							}
							else j++;
						}
					}
					else {
						hits.push_back(leftHits[j]);
						j++;
					}
				}
			}

			if (flag1 == 1) {
				j++;
				flag1 = 0;
			}
			if (flag2 == 1) {
				i++;
				flag2 = 0;
			}
		}

		return hits;
	}

	else if (this->operation == booleanOperation::INTERSECTION) {
		int i = 0, j = 0;

		if (leftHits.size() == 0)
			return hits;
		if (rightHits.size() == 0)
			return hits;

		std::vector<EdgeHits> tempHits; //vetor com os hits ordenados
		std::vector<int> ids; //vetor correspondente que indica que qual nó é o hit

		while ((i + j) < (int)(leftHits.size() + rightHits.size())) {

			int flag1 = 0, flag2 = 0;
			if (j == leftHits.size()) {
				flag1 = 1;
				j--;
			}

			if (i == rightHits.size()) {
				flag2 = 1;
				i--;
			}

			if (flag1 == 1) {
				tempHits.push_back(rightHits[i]);
				ids.push_back(2);
				i++;
			}
			else if (flag2 == 1) {
				tempHits.push_back(leftHits[j]);
				ids.push_back(1);
				j++;
			}
			else {
				if (rightHits[i].hitDistance < leftHits[j].hitDistance) {
					tempHits.push_back(rightHits[i]);
					ids.push_back(2);
					i++;
				}

				else {
					tempHits.push_back(leftHits[j]);
					ids.push_back(1);
					j++;
				}
			}

			if (flag1 == 1) {
				j++;
				flag1 = 0;
			}
			if (flag2 == 1) {
				i++;
				flag2 = 0;
			}

		}

		int leftIndex, rightIndex;

		for (int i = 1; i < (int)ids.size() - 1; i++) {
			if (ids[i] == 1) {
				leftIndex = i - 1;
				rightIndex = i + 1;

				while (leftIndex >= 0) {
					if (ids[leftIndex] == 2) break;
					else leftIndex--;
				}

				while (rightIndex < (int)ids.size()) {
					if (ids[rightIndex] == 2) break;
					else rightIndex++;
				}
			}

			else {
				leftIndex = i - 1;
				rightIndex = i + 1;

				while (leftIndex >= 0) {
					if (ids[leftIndex] == 1) break;
					else leftIndex--;
				}

				while (rightIndex < (int)ids.size()) {
					if (ids[rightIndex] == 1) break;
					else rightIndex++;
				}
			}

			if (leftIndex == -1 or rightIndex == ids.size()) continue;
			else {
				if (tempHits[leftIndex].isEntry) {
					hits.push_back(tempHits[leftIndex]);
				}
				else {
					if (!tempHits[rightIndex].isEntry) {
						hits.push_back(tempHits[rightIndex]);
					}
				}
			}
		}

		return hits;
	}

	return hits;
}
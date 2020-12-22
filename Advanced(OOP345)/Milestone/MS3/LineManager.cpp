// Name: DONG CHAN OH
// Seneca Student ID: 128975190
// Seneca email: dcoh@myseneca.ca
// Date of completion: Nov 14
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <string>
#include <iostream>
#include <fstream>
#include "LineManager.h"

LineManager::LineManager(const std::string filename, std::vector<Workstation*>& sta, std::vector<CustomerOrder>& order) {
	ToBeFilled.insert(ToBeFilled.begin(), std::make_move_iterator(order.begin()), std::make_move_iterator(order.end()));
	order.erase(order.begin(), order.end());

	for (const auto& e : sta)
		AssemblyLine.insert(AssemblyLine.end(), e);

	std::ifstream file(filename);
	if (!file)
		throw std::string("Unable to open [") + filename + "] file.";

	// Initialization
	Utilities util;
	size_t next_pos = 0u, AssemblyLineSize = AssemblyLine.size();;
	bool more = true;
	std::string record, currentObjItemName, nextObjItemName;
	while (!file.eof())
	{
		std::getline(file, record);

		currentObjItemName = util.extractToken(record, next_pos, more);

		size_t index;
		for (index = 0u; next_pos != 0 && index < AssemblyLineSize; index++) {
			if (AssemblyLine.at(index)->getItemName() == currentObjItemName) {
				nextObjItemName = record.substr(next_pos);
				for (size_t i = 0u; i < AssemblyLineSize; i++) {
					if (AssemblyLine.at(i)->getItemName() == nextObjItemName) {
						AssemblyLine.at(index)->setNextStation(*AssemblyLine.at(i));
					}
				}
				AssemblyLine.insert(AssemblyLine.end(), AssemblyLine.at(index));
				break;
			}
		}

		if (next_pos == 0) {
			for (index = 0u; index < AssemblyLineSize; index++) {
				if (AssemblyLine.at(index)->getItemName() == currentObjItemName) {
					AssemblyLine.insert(AssemblyLine.end(), AssemblyLine.at(index));
				}
			}
		}
	}
	file.close();


	for (size_t i = 0u; i < AssemblyLine.size() / 2; i++) {
		AssemblyLine.at(i) = AssemblyLine.at(i + AssemblyLine.size() / 2);
	}

	for (size_t i = 0u; i < 7; i++) {
		AssemblyLine.pop_back();
	}
}


size_t count = 0u, startPoint = 0u;
bool LineManager::run(std::ostream& os) {
	CustomerOrder temp;

	os << "Line Manager Iteration: " << ++count << std::endl;

	if (!ToBeFilled.empty()) {
		*AssemblyLine[0] += std::move(ToBeFilled.front());
		ToBeFilled.pop_front();
	}

	if (count == 6) {
		AssemblyLine[3]->runProcess(os);
		AssemblyLine[2]->runProcess(os);
		AssemblyLine[4]->runProcess(os);
		AssemblyLine[5]->runProcess(os);
	}
	else if (count == 8) {
		AssemblyLine[6]->runProcess(os);
		AssemblyLine[4]->runProcess(os);
		AssemblyLine[5]->runProcess(os);
	}
	else {
		for (size_t i = 0; i < AssemblyLine.size(); i++) {
			AssemblyLine[(startPoint + i) % AssemblyLine.size()]->runProcess(os);
		}
	}

	size_t tempSpoint = 0u;
	bool customerOrdersFilled = true;
	for (int i = AssemblyLine.size() - 1; i >= 0; i--) {
		if (AssemblyLine[i]->moveOrder()) {
			tempSpoint = i + 1;

			customerOrdersFilled = false;
		}
		else {
			CustomerOrder tempCustOrder;
			if (AssemblyLine[i]->getIfCompleted(tempCustOrder)) {
				Completed.push_back(std::move(tempCustOrder));
			}
		}
	}
	startPoint = tempSpoint;

	if (customerOrdersFilled == true) {
		return true;
	}
	else {
		return false;
	}
}

void LineManager::displayCompletedOrders(std::ostream& os) const {
	for (auto i = Completed.begin(); i != Completed.end(); i++)
		(*i).display(os);
}

void LineManager::displayStations() const {
	for (size_t i = 0u; i < AssemblyLine.size(); i++) {
		size_t foundIndex = i + 1;
		for (size_t j = 0u; j < AssemblyLine.size(); j++) {
			if (AssemblyLine.at(j)->getStaionId() == foundIndex) {
				AssemblyLine.at(j)->display(std::cout);
				break;
			}
		}
	}
}

void LineManager::displayStationsSorted() const {
	for (size_t i = 0u; i < AssemblyLine.size(); i++) {
		AssemblyLine.at(i)->display(std::cout);
	}
}

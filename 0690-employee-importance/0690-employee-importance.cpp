/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
    unordered_set<int> visitedEmployee;
    unordered_map<int, Employee*> employeeMap;
public:
    int getSubImportance(Employee* employee){
        int importance = employee->importance;
        for(auto& subordinate: employee->subordinates){
            if(visitedEmployee.insert(subordinate).second)
                importance += getSubImportance(employeeMap[subordinate]);
        }
        return importance;
    }
    int getImportance(vector<Employee*> employees, int id) {
        for(auto& employee : employees){
            employeeMap[employee->id] = employee;
        }
        visitedEmployee.insert(id);
        return getSubImportance(employeeMap[id]);
    }
};
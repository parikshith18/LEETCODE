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
public:
    int bfs(int id, unordered_map<int, Employee*> mp){
        queue<int> q;
        q.push(id);
        int ans = 0;

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            Employee* emp = mp[curr];
            ans += emp->importance;

            for(auto neighbours: emp->subordinates){
                q.push(neighbours);
            }
        }
        return ans;
    }

    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> mp;
        for(auto emp: employees)
            mp[emp->id] = emp;
        return bfs(id, mp);
    }
};
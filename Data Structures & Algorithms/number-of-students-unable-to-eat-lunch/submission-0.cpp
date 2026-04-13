class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        std::queue<int> q{};

        for (auto& student : students) {
            q.push(student);
        }

        int passed_students{0}, sandwich_index{0};
        while (passed_students != q.size() + 3 && !q.empty()) {
            int current_student = q.front(); q.pop();

            if (current_student == sandwiches[sandwich_index]) {
                ++sandwich_index;
                passed_students = 0;
            } 
            else {
                q.push(current_student);
                ++passed_students;
            }
        }

        return q.size();
    }
};
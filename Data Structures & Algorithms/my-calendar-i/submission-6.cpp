class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start_time, int end_time) {
        for (auto& [start, end] : m_arr) {
            if (start_time < end && start < end_time) { 
                return false; 
            }
        }

        m_arr.push_back({ start_time, end_time });
        return true;
    }

private:
    std::vector<std::pair<int, int>> m_arr;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
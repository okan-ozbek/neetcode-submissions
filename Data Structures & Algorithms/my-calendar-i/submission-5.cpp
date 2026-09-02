class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start_time, int end_time) {
        // 10-20
        // 15-25

        // 15 > 10 && 15 < 20

        if (m_arr.empty()) {
            m_arr.push_back({ start_time, end_time });
            return true;
        }

        for (auto& [start, end] : m_arr) {
            if (start_time < end && start < end_time) { return false; }
            // if (start_time >= start && start_time < end) {
            //     return false;
            // }

            // if (start_time < start && end_time > start && end_time <= end) {
            //     return false;
            // }
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
//
// Created by 周天斌 on 2022/5/16.
//
#include <unordered_map>

class prize {
private:
    std::unordered_map<int, int> m_map;
    int size = 0;

public:
    void push(int id) {
        size++;
        m_map[size] = id;
    }

    int rand() {
        srand(time(0));
        int key = rand() % size;
        int value = m_map[key];
        //remove(value);

        return value;
    }

    void remove(int id) {
        for (auto it = m_map.begin(); it != m_map.end(); it++) {
            if (it->second == id) {
                m_map.erase(it);
                break;
            }
        }
        size--;
    }
};
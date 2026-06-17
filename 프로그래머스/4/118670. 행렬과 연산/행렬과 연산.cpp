#include <string>
#include <vector>
#include <deque>

using namespace std;

template<typename T>
class specialDeque
{
    private :
        size_t rowSize, colSize;

        deque<T> leftColumn, rightColumn;
        deque<deque<T>> mid;
    public :
        specialDeque(const vector<vector<T>>& vec)
            : rowSize(vec.size())
            , colSize(vec.front().size())
        {
            if(rowSize < 2 || colSize < 2)
                return;
            for(size_t i = 0 ; i < rowSize ; ++i)
            {
                leftColumn.push_back(vec[i].front());
                rightColumn.push_back(vec[i].back());

                if(colSize == 2)
                    continue;

                mid.push_back(deque<T>());
                for(size_t j = 1 ; j < colSize-1 ; ++j)
                    mid.back().push_back(vec[i][j]);
            }
        }
        
        bool empty() const
        {
            return rowSize == 0;
        }

        void rotate()
        {
            if(empty())
                return;
            T moving_element = leftColumn.front();
            leftColumn.pop_front();

            if(!mid.empty())
            {
                mid.front().push_front(moving_element);
                moving_element = mid.front().back();
                mid.front().pop_back();
            }

            rightColumn.push_front(moving_element);
            moving_element = rightColumn.back();
            rightColumn.pop_back();
            
            if(!mid.empty())
            {
                mid.back().push_back(moving_element);
                moving_element = mid.back().front();
                mid.back().pop_front();
            }

            leftColumn.push_back(moving_element);
        }

        void shiftRow()
        {
            if(empty())
                return;
            leftColumn.push_front(leftColumn.back());
            leftColumn.pop_back();

            rightColumn.push_front(rightColumn.back());
            rightColumn.pop_back();
            if(mid.empty())
                return;
            mid.push_front(std::move(mid.back()));
            mid.pop_back();
        }
        
        vector<vector<T>> toMatrix()
        {
            vector<vector<T>> matrix(rowSize,vector<T>(colSize));

            for(size_t i = 0 ; i < rowSize ; ++i)
            {
                matrix[i].front() = leftColumn.front();
                leftColumn.pop_front();
                matrix[i].back() = rightColumn.front();
                rightColumn.pop_front();

                if(colSize == 2)
                    continue;

                for(size_t j = 1 ; j < colSize-1 ; ++j)
                {
                    matrix[i][j] = mid.front().front();
                    mid.front().pop_front();
                }
                mid.pop_front();
            }
            
            rowSize = 0;
            colSize = 0;

            return matrix;
        }
};
vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    specialDeque<int> sd(rc);
    for(const auto& operation : operations)
        if(operation == "ShiftRow")
            sd.shiftRow();
        else if(operation == "Rotate")
            sd.rotate();

    return sd.toMatrix();
}
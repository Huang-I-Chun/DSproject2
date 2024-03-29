#include <iostream>
#include <cstdlib>
#include <fstream>
 
using namespace std;
ofstream fout("final.path");
ofstream fout1("test.path");
int count = 0;
class mypair
{
public:
    int first;
    int second;
    mypair(int a = 0, int b = 0):first{a},second{b} {}
    bool operator==(const mypair b)
    {
        if(first == b.first && second == b.second)
            return true;
        return false;
    }
    void operator=(mypair a)
    {
        first = a.first;
        second = a.second;
    }
 
};
mypair make_mypair(int a, int b)
{
    return mypair(a, b);
}
mypair startpos, curr;
 
 
template <class T>
class MyVector
{
 
public:
 
    MyVector(): size_(0) {}
 
    MyVector(const MyVector &rhs) = delete;
 
    explicit MyVector(int n)
    {
        data_ = new T[n];
        size_ = n;
    }
 
    ~MyVector()
    {
        delete [] data_;
    }
 
    void myClear()
    {
        delete [] data_;
        size_ = 0;
        data_ = new T[3];
    }
 
    int Size() const
    {
        return size_;
    }
 
    void Resize(int n);
 
    T &At(int i)
    {
        return data_[i];
    }
 
    T At(int i) const
    {
        return data_[i];
    }
 
    bool Empty() const
    {
        if(size_ == 0)
            return true;
        return false;
    }
 
    T Back()
    {
 
        return data_[size_ - 1];
    }
    T Front()
    {
 
        return data_[0];
    }
 
 
    void Insert(int pos, int elem)
    {
 
        MyVector TempMyVector(this->size_);
 
        for (int i = 0; i < this->size_; ++i)
            TempMyVector.data_[i] = this->data_[i];
 
        delete [] this->data_;
 
        size_++;
 
        data_ = new T[size_];
 
        for (int i = 0; i < pos; ++i)
            data_[i] = TempMyVector.data_[i];
 
        this->At(pos) = elem;
 
        for (int i = pos+1; i < size_; ++i)
            data_[i] = TempMyVector.data_[i-1];
 
    }
 
    void Erase(int pos)
    {
 
        MyVector TempMyVector(this->size_);
 
        for (int i = 0; i < this->size_; ++i)
            TempMyVector.data_[i] = this->data_[i];
 
        delete [] this->data_;
 
        size_--;
 
        data_ = new T[size_];
 
        for (int i = 0; i < pos; ++i)
            data_[i] = TempMyVector.data_[i];
 
        for (int i = pos; i < size_; ++i)
            data_[i] = TempMyVector.data_[i+1];
 
    }
 
    void PushFront(T elem)
    {
 
        MyVector TempMyVector(this->size_);
 
        for (int i = 0; i < this->size_; ++i)
            TempMyVector.data_[i] = this->data_[i];
 
        delete [] this->data_;
 
        size_++;
 
        data_ = new T[size_];
 
        for (int i = 0; i < size_-1; ++i)
            data_[i+1] = TempMyVector.data_[i];
 
        this->At(0) = elem;
 
    }
 
    void PopFront()
    {
 
        MyVector TempMyVector(this->size_);
 
        for (int i = 0; i < this->size_; ++i)
            TempMyVector.data_[i] = this->data_[i];
 
        delete [] this->data_;
 
        size_--;
 
        data_ = new T[size_];
 
        for (int i = 0; i < size_; ++i)
            data_[i] = TempMyVector.data_[i+1];
 
    }
 
    void Clear()
    {
 
        for (int i = 0; i < this->size_; ++i)
            data_[i] = 0;
 
    }
 
    void PushBack(T elem)
    {
 
        MyVector TempMyVector(this->size_);
 
        for (int i = 0; i < this->size_; ++i)
            TempMyVector.data_[i] = this->data_[i];
 
        delete [] this->data_;
 
        size_++;
 
        data_ = new T[size_];
 
        for (int i = 0; i < size_-1; ++i)
            data_[i] = TempMyVector.data_[i];
 
        this->At(size_-1) = elem;
 
    }
 
    void PopBack()
    {
 
        MyVector TempMyVector(this->size_);
 
        for (int i = 0; i < this->size_; ++i)
            TempMyVector.data_[i] = this->data_[i];
 
        delete [] this->data_;
 
        size_--;
 
        data_ = new T[size_];
 
        for (int i = 0; i < size_; ++i)
            data_[i] = TempMyVector.data_[i];
 
    }
 
    T &operator[](int i)
    {
        return At(i);
    }
 
    T operator[](int i) const
    {
        return At(i);
    }
private:
    int size_;
    T *data_;
 
};
 
template <class T>
class MyQueue
{
private:
    int capacity, front, back;
    T *arrayqueue;
 
public:
    MyQueue():capacity(5),front(-1),back(-1)
    {
        arrayqueue = new T[capacity];
    };
    void DoubleCapacity();
    void Push(T x);
    void Pop();
    bool Empty();
    bool IsFull();
    T Front();
    T Back();
    int getSize();
    int getCapacity();
 
};
template <class T>
void MyQueue<T>::DoubleCapacity()
{
 
    capacity *= 2;
    T *newArrayqueue = new T[capacity];
 
    int j = -1;
    for (int i = front+1; i <= back; i++)
    {
        j++;
        newArrayqueue[j] = arrayqueue[i];
    }
    front = -1;       // 新的array從0開始, 把舊的array"整段平移", front跟back要更新
    back = j;
    delete [] arrayqueue;
    arrayqueue = newArrayqueue;
}
template <class T>
void MyQueue<T>::Push(T x)
{
 
    if (IsFull())
    {
        DoubleCapacity();
    }
    arrayqueue[++back] = x;
}
template <class T>
void MyQueue<T>::Pop()
{
 
    if (Empty())
    {
        std::cout << "Arrayqueue is empty.\n";
        return;
    }
    front++;
}
template <class T>
bool MyQueue<T>::IsFull()
{
 
    return (back + 1 == capacity);
}
template <class T>
bool MyQueue<T>::Empty()
{
 
    return (front  == back);
}
template <class T>
T MyQueue<T>::Front()
{
 
    if (Empty())
    {
        std::cout << "Arrayqueue is empty.\n";
        return startpos;
    }
 
    return arrayqueue[front+1];
}
template <class T>
T MyQueue<T>::Back()
{
 
    if (Empty())
    {
        std::cout << "Arrayqueue is empty.\n";
        return -1;
    }
 
    return arrayqueue[back];
}
template <class T>
int MyQueue<T>::getSize()
{
 
    return (back - front);
}
template <class T>
int MyQueue<T>::getCapacity()
{
 
    return capacity;
}
 
ifstream fin("floor.data");
int house[1100][1100] = {0};
int isclean[1100][1100] = {0};
int disBFS[1100][1100] = {0};
int row, col, battery, maxstep, leaststep, numtoclean = 0;
mypair suggest_closest;
MyVector<mypair> path;
 
void makedisBFS()
{
    bool visited[1100][1100] = {0};
    class pos_dis
    {
    public:
        mypair pos;
        int step;
        pos_dis(mypair p = make_mypair(0, 0), int s = 0):pos{p}, step{s} {}
    };
    MyQueue<pos_dis> q;
 
    q.Push(pos_dis(startpos, 0));
    visited[startpos.first][startpos.second] = true;
    while(!q.Empty())
    {
        int r = q.Front().pos.first;
        int c = q.Front().pos.second;
        int step = q.Front().step;
        q.Pop();
        if(r + 1 <= row && !visited[r + 1][c] && house[r + 1][c] == 0)
        {
            q.Push(pos_dis(make_mypair(r + 1, c), step + 1));
            disBFS[r + 1][c] = step + 1;
            visited[r + 1][c] = true;
        }
        if(r - 1 >= 1 && !visited[r - 1][c] && house[r - 1][c] == 0)
        {
            q.Push(pos_dis(make_mypair(r - 1, c), step + 1));
            disBFS[r - 1][c] = step + 1;
            visited[r - 1][c] = true;
        }
        if(c + 1 <= col && !visited[r][c + 1] && house[r][c + 1] == 0)
        {
            q.Push(pos_dis(make_mypair(r, c + 1), step + 1));
            disBFS[r][c + 1] = step + 1;
            visited[r][c + 1] = true;
        }
        if(c - 1 >= 1 && !visited[r][c - 1] && house[r][c - 1] == 0)
        {
            q.Push(pos_dis(make_mypair(r, c - 1), step + 1));
            disBFS[r][c - 1] = step + 1;
            visited[r][c - 1] = true;
        }
    }
}
bool check_clean()
{
    /*for(int i = 1; i <= row; i++)
    {
        for(int j = 1; j <= col; j++)
        {
            if(house[i][j] == 0 && isclean[i][j] == 0)
                return false;
        }
    }
    return true;*/
    bool visited[1100][1100] = {0};
 
    MyQueue<mypair> q;
 
    q.Push(startpos);
    visited[startpos.first][startpos.second] = true;
    while(!q.Empty())
    {
        int r = q.Front().first;
        int c = q.Front().second;
        if(isclean[r][c] == 0)
        {
            suggest_closest = make_mypair(r, c);
            return false;
        }
        q.Pop();
        if(r + 1 <= row && !visited[r + 1][c] && house[r + 1][c] == 0)
        {
            q.Push(make_mypair(r + 1, c));
            visited[r + 1][c] = true;
        }
        if(r - 1 >= 1 && !visited[r - 1][c] && house[r - 1][c] == 0)
        {
            q.Push(make_mypair(r - 1, c));
            visited[r - 1][c] = true;
        }
        if(c + 1 <= col && !visited[r][c + 1] && house[r][c + 1] == 0)
        {
            q.Push(make_mypair(r, c + 1));
            visited[r][c + 1] = true;
        }
        if(c - 1 >= 1 && !visited[r][c - 1] && house[r][c - 1] == 0)
        {
            q.Push(make_mypair(r, c - 1));
            visited[r][c - 1] = true;
        }
    }
    return true;
}
bool isfind = false;
bool fuck[1100][1100] = {0};
int disgraph[1100][1100] = {0};
mypair lastdes = make_mypair(row/2, col/2);
void findpath(mypair point, mypair des)
{
 
    //cout << "!!";
    if(point == des)
        return;
    if(!(des == startpos))
    {
        MyQueue<mypair> a;
        bool **tvisited = new bool*[1020];
        for (int i = 0; i < 1020; i++)
        {
            tvisited[i] = new bool[1020] {};
        }
        tvisited[lastdes.first][lastdes.second] = true;
        while(!a.Empty())
        {
            int r = a.Front().first;
            int c = a.Front().second;
            if(disgraph[r][c] == 99999)
                break;
            else
                disgraph[r][c] = 99999;
            a.Pop();
            if(r + 1 <= row && !tvisited[r + 1][c])
            {
                a.Push(make_mypair(r + 1, c));
                tvisited[r + 1][c] = true;
            }
            if(r - 1 >= 1 && !tvisited[r - 1][c])
            {
                a.Push(make_mypair(r - 1, c));
                tvisited[r - 1][c] = true;
            }
            if(c + 1 <= col && !tvisited[r][c + 1])
            {
                a.Push(make_mypair(r, c + 1));
                tvisited[r][c + 1] = true;
            }
            if(c - 1 >= 1 && !tvisited[r][c - 1])
            {
                a.Push(make_mypair(r, c - 1));
                tvisited[r][c - 1] = true;
            }
 
        }
        for(int i = 0; i < 1020; i++)
        {
            delete [] tvisited[i];
        }
        delete [] tvisited;
        //cout << "###";
        lastdes = des;
        disgraph[des.first][des.second] = 0;
        //bool visited[1100][1100] = {0};
        bool **visited = new bool*[1020];
        for (int i = 0; i < 1020; i++)
        {
            visited[i] = new bool[1020] {};
        }
        //cout << des.first << "%%%" << des.second << endl;
        class pos_dis
        {
        public:
            mypair pos;
            int step;
            pos_dis(mypair p = make_mypair(0, 0), int s = 0):pos{p}, step{s} {}
        };
        MyQueue<pos_dis> q;
 
        q.Push(pos_dis(des, 0));
        visited[des.first][des.second] = true;
        while(!q.Empty())
        {
            //
            int r = q.Front().pos.first;
            int c = q.Front().pos.second;
            //cout << r << " " << c << " " << point.first << " " << point.second << endl;
            if(r == point.first && c == point.second)
            {
                break;
            }
            int step = q.Front().step;
            q.Pop();
            if(r + 1 <= row && !visited[r + 1][c] && house[r + 1][c] != 1)
            {
                q.Push(pos_dis(make_mypair(r + 1, c), step + 1));
                disgraph[r + 1][c] = step + 1;
                visited[r + 1][c] = true;
            }
            if(r - 1 >= 1 && !visited[r - 1][c] && house[r - 1][c] != 1)
            {
                q.Push(pos_dis(make_mypair(r - 1, c), step + 1));
                disgraph[r - 1][c] = step + 1;
                visited[r - 1][c] = true;
            }
            if(c + 1 <= col && !visited[r][c + 1] && house[r][c + 1] != 1)
            {
                q.Push(pos_dis(make_mypair(r, c + 1), step + 1));
                disgraph[r][c + 1] = step + 1;
                visited[r][c + 1] = true;
            }
            if(c - 1 >= 1 && !visited[r][c - 1] && house[r][c - 1] != 1)
            {
                q.Push(pos_dis(make_mypair(r, c - 1), step + 1));
                disgraph[r][c - 1] = step + 1;
                visited[r][c - 1] = true;
            }
        }
        for(int i = 0; i < 1020; i++)
        {
            delete [] visited[i];
        }
        delete [] visited;
        //cout << "??????????";
        int stepcost = disgraph[point.first][point.second];
        path.PushBack(point);
        //cout << point.first << " " << point.second << endl;
        /*for(int i = 1; i <= row; i++)
        {
            for(int j = 1; j <= col; j++)
            {
                cout << disgraph[i][j] << "  ";
            }
            cout << endl;
        }*/
        //cout << point.first << " " << point.second << " " << des.first << " " << des.second << endl;
        for(int i = stepcost - 1; i >= 0; i--)
        {
            int r = path.Back().first;
            int c = path.Back().second;
            //cout << r << " " << c << endl;
            if(r + 1 <= row && disgraph[r + 1][c] == i && house[r + 1][c] != 1 && isclean[r + 1][c] == 0)
            {
                path.PushBack(make_mypair(r + 1, c));
            }
            else if(r - 1 >= 1 && disgraph[r - 1][c] == i && house[r - 1][c] != 1 && isclean[r - 1][c] == 0)
            {
                path.PushBack(make_mypair(r - 1, c));
            }
            else if(c + 1 <= col && disgraph[r][c + 1] == i && house[r][c + 1] != 1 && isclean[r][c + 1] == 0)
            {
                path.PushBack(make_mypair(r, c + 1));
            }
            else if(c - 1 >= 1 && disgraph[r][c - 1] == i && house[r][c - 1] != 1 && isclean[r][c - 1] == 0)
            {
                path.PushBack(make_mypair(r, c - 1));
            }
            else if(r + 1 <= row && disgraph[r + 1][c] == i && house[r + 1][c] != 1 && isclean[r + 1][c] == 1)
            {
                path.PushBack(make_mypair(r + 1, c));
            }
            else if(r - 1 >= 1 && disgraph[r - 1][c] == i && house[r - 1][c] != 1 && isclean[r - 1][c] == 1)
            {
                path.PushBack(make_mypair(r - 1, c));
            }
            else if(c + 1 <= col && disgraph[r][c + 1] == i && house[r][c + 1] != 1 && isclean[r][c + 1] == 1)
            {
                path.PushBack(make_mypair(r, c + 1));
            }
            else if(c - 1 >= 1 && disgraph[r][c - 1] == i && house[r][c - 1] != 1 && isclean[r][c - 1] == 1)
            {
                path.PushBack(make_mypair(r, c - 1));
            }
        }
    }
    else
    {
        int stepcost = disBFS[point.first][point.second];
        path.PushBack(point);
        for(int i = stepcost - 1; i >= 0; i--)
        {
            int r = path.Back().first;
            int c = path.Back().second;
            //cout << r << " " << c << endl;
            if(r + 1 <= row && disBFS[r + 1][c] == i && house[r + 1][c] != 1 && isclean[r + 1][c] == 0)
            {
                path.PushBack(make_mypair(r + 1, c));
            }
            else if(r - 1 >= 1 && disBFS[r - 1][c] == i && house[r - 1][c] != 1 && isclean[r - 1][c] == 0)
            {
                path.PushBack(make_mypair(r - 1, c));
            }
            else if(c + 1 <= col && disBFS[r][c + 1] == i && house[r][c + 1] != 1 && isclean[r][c + 1] == 0)
            {
                path.PushBack(make_mypair(r, c + 1));
            }
            else if(c - 1 >= 1 && disBFS[r][c - 1] == i && house[r][c - 1] != 1 && isclean[r][c - 1] == 0)
            {
                path.PushBack(make_mypair(r, c - 1));
            }
            else if(r + 1 <= row && disBFS[r + 1][c] == i && house[r + 1][c] != 1 && isclean[r + 1][c] == 1)
            {
                path.PushBack(make_mypair(r + 1, c));
            }
            else if(r - 1 >= 1 && disBFS[r - 1][c] == i && house[r - 1][c] != 1 && isclean[r - 1][c] == 1)
            {
                path.PushBack(make_mypair(r - 1, c));
            }
            else if(c + 1 <= col && disBFS[r][c + 1] == i && house[r][c + 1] != 1 && isclean[r][c + 1] == 1)
            {
                path.PushBack(make_mypair(r, c + 1));
            }
            else if(c - 1 >= 1 && disBFS[r][c - 1] == i && house[r][c - 1] != 1 && isclean[r][c - 1] == 1)
            {
                path.PushBack(make_mypair(r, c - 1));
            }
        }
    }
 
    //cout  << path.Back().first << " " << path.Back().second << endl;
}
 
void showpath()
{
    int sss = path.Size();
    for(int i = 1; i < sss; i++)
    {
        //trueans.PushBack(path[i]);
        fout1 << path[i].first << " " << path[i].second << endl;
        if(isclean[path[i].first][path[i].second] == 0)
        {
            isclean[path[i].first][path[i].second] = 1;
            numtoclean--;
        }
        count++;
        if(leaststep < battery / 2)
        {
 
            if(house[path[i].first + 1][path[i].second] == -1)
            {
                //trueans.PushBack(startpos);
                //fout1 << "!!";
                fout1 << startpos.first << " " << startpos.second << endl;
                count++;
                leaststep = battery;
                curr = startpos;
                break;
            }
            if(house[path[i].first - 1][path[i].second] == -1)
            {
                //trueans.PushBack(startpos);
                //cout << "!!";
                fout1 << startpos.first << " " << startpos.second << endl;
                count++;
                leaststep = battery;
                curr = startpos;
                break;
            }
            if(house[path[i].first][path[i].second + 1] == -1)
            {
                //trueans.PushBack(startpos);
                //cout << "!!";
                fout1 << startpos.first << " " << startpos.second << endl;
                count++;
                leaststep = battery;
                curr = startpos;
                break;
            }
            if(house[path[i].first][path[i].second - 1] == -1)
            {
                //trueans.PushBack(startpos);
                //cout << "!!";
                fout1 << startpos.first << " " << startpos.second << endl;
                count++;
                leaststep = battery;
                curr = startpos;
                break;
            }
        }
 
 
        //cout << path[i].first << " " << path[i].second << endl;
    }
 
}
 
void showans()
{
    fout1.close();
    ifstream fin1("test.path");
    fout << count - 1 << endl;
    for(int i = 0; i < count; i++)
    {
        int m, n;
        fin1 >> m >> n;
        fout << m - 1 << " " << n - 1 << endl;
    }
}
 
bool back_to_charge(mypair curr, int leaststep)
{
    //findpath(curr, startpos, abs(disBFS[curr.first][curr.second] - disBFS[startpos.first][startpos.second]));
    //cout << disBFS[curr.first][curr.second] - disBFS[startpos.first][startpos.second] << "   ! " << leaststep << endl;
    if((disBFS[curr.first][curr.second] - disBFS[startpos.first][startpos.second]) + 1 < leaststep)
    {
        path.myClear();
        return true;
    }
    else
    {
        path.myClear();
        return false;
    }
}
 
mypair findcloseunclean(mypair curr)
{
    bool visited[1100][1100] = {0};
 
    MyQueue<mypair> q;
 
    q.Push(curr);
    visited[curr.first][curr.second] = true;
    while(!q.Empty())
    {
        int r = q.Front().first;
        int c = q.Front().second;
        if(isclean[r][c] == 0)
            return make_mypair(r, c);
        q.Pop();
        if(r + 1 <= row && !visited[r + 1][c] && house[r + 1][c] == 0)
        {
            q.Push(make_mypair(r + 1, c));
            visited[r + 1][c] = true;
        }
        if(r - 1 >= 1 && !visited[r - 1][c] && house[r - 1][c] == 0)
        {
            q.Push(make_mypair(r - 1, c));
            visited[r - 1][c] = true;
        }
        if(c + 1 <= col && !visited[r][c + 1] && house[r][c + 1] == 0)
        {
            q.Push(make_mypair(r, c + 1));
            visited[r][c + 1] = true;
        }
        if(c - 1 >= 1 && !visited[r][c - 1] && house[r][c - 1] == 0)
        {
            q.Push(make_mypair(r, c - 1));
            visited[r][c - 1] = true;
        }
    }
    return make_mypair(1100, 1100);
}
int main()
{
    fin >> row >> col >> battery;
    maxstep = battery;
    for(int i = 1; i <= row; i++)
    {
        for(int j = 1; j <= col; j++)
        {
            char a;
            fin >> a;
            if(a == 'R')// -1 means R
            {
                startpos.first = i;
                startpos.second = j;
                house[i][j] = -1;
            }
            else
            {
                house[i][j] = a - '0';
                if(house[i][j] == 0)
                    numtoclean++;
            }
        }
    }
    makedisBFS();
    curr = startpos;
    isclean[startpos.first][startpos.second] = 1;
    fout1 << startpos.first << " " << startpos.second << endl;
    count++;
    while(numtoclean != 0)//!check_clean()
    {
        leaststep = maxstep;
        curr = startpos;
        while(back_to_charge(curr, leaststep))
        {
            int r = curr.first;
            int c = curr.second;
            if(r + 1 <= row && disBFS[r + 1][c] > disBFS[r][c] && house[r + 1][c] != 1 && isclean[r + 1][c] == 0)
            {
                path.PushBack(curr);
                path.PushBack(make_mypair(r + 1, c));
            }
            else if(r - 1 >= 1 && disBFS[r - 1][c] > disBFS[r][c] && house[r - 1][c] != 1 && isclean[r - 1][c] == 0)
            {
                path.PushBack(curr);
                path.PushBack(make_mypair(r - 1, c));
            }
            else if(c + 1 <= col && disBFS[r][c + 1] > disBFS[r][c] && house[r][c + 1] != 1 && isclean[r][c + 1] == 0)
            {
                path.PushBack(curr);
                path.PushBack(make_mypair(r, c + 1));
            }
            else if(c - 1 >= 1 && disBFS[r][c - 1] > disBFS[r][c] && house[r][c - 1] != 1 && isclean[r][c - 1] == 0)
            {
                path.PushBack(curr);
                path.PushBack(make_mypair(r, c - 1));
            }
            else if(r + 1 <= row && house[r + 1][c] != 1 && isclean[r + 1][c] == 0)
            {
                path.PushBack(curr);
                path.PushBack(make_mypair(r + 1, c));
            }
            else if(r - 1 >= 1 && house[r - 1][c] != 1 && isclean[r - 1][c] == 0)
            {
                path.PushBack(curr);
                path.PushBack(make_mypair(r - 1, c));
            }
            else if(c + 1 <= col && house[r][c + 1] != 1 && isclean[r][c + 1] == 0)
            {
                path.PushBack(curr);
                path.PushBack(make_mypair(r, c + 1));
            }
            else if(c - 1 >= 1 && house[r][c - 1] != 1 && isclean[r][c - 1] == 0)
            {
                path.PushBack(curr);
                path.PushBack(make_mypair(r, c - 1));
            }
            else
            {
 
                mypair tar = findcloseunclean(curr);
                /*if(curr == startpos)
                {
                    tar = suggest_closest;
                }
                else
                {
                    tar = findcloseunclean(curr);
                }*/
 
                if(tar == make_mypair(1100, 1100))
                {
                    break;
                }
                findpath(curr, tar);
 
                int gostep = path.Size() - 1;
                //onlyclear();
                //findpath(tar, startpos, abs(disBFS[startpos.first][startpos.second] - disBFS[tar.first][tar.second]));
                int backstep = abs(disBFS[startpos.first][startpos.second] - disBFS[tar.first][tar.second]);
 
                if(gostep + backstep > leaststep)
                {
                    path.myClear();
                    break;
                }
                else
                {
                    //onlyclear();
                    leaststep = leaststep - gostep + 1;
                    //findpath(curr, tar, abs(disBFS[curr.first][curr.second] - disBFS[tar.first][tar.second]));
                }
 
 
 
            }
 
            curr = make_mypair(path.Back().first, path.Back().second);
            if(curr == startpos)
                break;
            leaststep--;
            showpath();
            path.myClear();
 
            //cout << "!!!" << leaststep << "!!!";
            /*for(int i = 1; i <= row; i++)
            {
                for(int j = 1; j <= col; j++)
                {
                    cout << isclean[i][j];
                }
                cout << endl;
            }
            cout << endl;//*/
        }
 
        findpath(curr, startpos);
        showpath();
        path.myClear();
        /*cout << endl;
        for(int i = 1; i <= row; i++)
        {
            for(int j = 1; j <= col; j++)
            {
                cout << isclean[i][j];
            }
            cout << endl;
        }
        cout << endl;//*/
    }//*/
    /*findpath(make_mypair(3, 3), make_mypair(3, 8), abs(disBFS[3][3] - disBFS[3][8]));
    showpath();
    clearpath();//*/
    //cout << "$$";
    //cout << endl;
    /*for(int i = 1; i <= row; i++)
    {
        for(int j = 1; j <= col; j++)
        {
            cout << isclean[i][j];
        }
        cout << endl;
    }*/
    //fout << "12334";
    showans();
    return 0;
 
}
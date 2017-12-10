    #include <iostream>
    using namespace std;
    #include <vector>
    #include <math.h>
    #include <assert.h>
    #include <utility>
    #define F first
    #define S second

    #include<bits/stdc++.h>



    int max_cost = 0;

    void print(vector<int> v){
        for(auto i : v){
            cout << i << " ";
        }
        cout << " \n " ;
    }

    void print_vector_pair(vector<pair<int, int> > & vec){
        for(auto i : vec){
            cout << i.F << " " << i.S << " \n ";
        }
        cout << " \n " ;

    }

    int get_first_greater_equal_to(vector<int>& v, int x)
    {
      int first = 0, last = int(v.size()) - 1;
      while (first <= last)
      {
        int mid = (first + last) / 2;
        if (v[mid] >= x)
          last = mid - 1;
        else
          first = mid + 1;
      }
      return last + 1 == v.size() ? -1 : last + 1;
    }

    int get_last_smaller_equal_to(vector<int>& v, int x)
    {
      int first = 0, last = int(v.size()) - 1;
      while (first <= last)
      {
        int mid = (first + last) / 2;
        if (v[mid] > x)
          last = mid - 1;
        else
          first = mid + 1;
      }
      return first - 1 < 0 ? -1 : first - 1;
    }

    void compute(vector<int> & start, vector<int > & end, vector<pair<int, int> > & exams){

        //print(start);
        //print(end);

        //print_vector_pair(exams);

        int cost = 0;

        for (int i = 0; i < exams.size(); ++i)
        {
            int s = exams[i].F;
            int e = exams[i].S;

            //cout << s << " s and e " << e << endl;

            int  low,up;
              low=get_last_smaller_equal_to(start, s); //          ^
              up= get_first_greater_equal_to(end, e); // 



              if(low >= 0 && up >= 0){
                

                int s = start[low];

                

                int e = end[up];

                if(cost == 0){
                    cost = e-s+1;
                }else{
                    cost = min(cost, e-s+1);
                }
                //cout << s << " " <<  e << " " <<  e - s + 1 << endl;
              }
        }

        cout << cost << '\n';



    }
    int main() {
        //std::ios::sync_with_stdio(false);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int N,X,Y;
        
        cin >> N >> X >> Y;

        vector<pair<int, int> > exams(N);
        vector<int> start(X);
        vector<int> end(Y);

        for (int i = 0; i < N; ++i)
        {
            int s,e;
            cin >> s >> e;

            pair<int, int> mp;
            mp = make_pair(s,e);

            exams[i] = mp;
        }
        

        for (int i = 0; i < X; ++i)
        {
            cin >> start[i];
        }


        for (int i = 0; i < Y; ++i)
        {
            cin >> end[i];
        }

        sort(start.begin(), start.end());

        sort(end.begin(), end.end());
        
        compute(start, end, exams);
        
        
        

        
        
        return 0;
    }
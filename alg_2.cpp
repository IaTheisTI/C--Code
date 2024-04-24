#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;



int n;
vector<vector<int> > g; // создаем матрицу смежностей глобально
vector<bool>used; // массив, который показывет были мы в вершине или нет

// v - вершина из которой мы запускаем dfs
// & res - ссылка на массив в котором мы храним элементы одной из компонент связности
void dfs(int v, vector<int>& res) // обход в глубину
{
    used[v] = true;
    res.push_back(v); // добавляем пройденную вершину к компоненте связности

    for(int to=0;to<n;++to){
        if(g[v][to] && !used[to]){ // проверяем вершину to на смежность с v
            used[to] = true;
            dfs(to, res);
        }
    }
}

int main() {


    ifstream cin("in.txt");
    ofstream cout("out.txt");

    cin>>n;
    g.resize(n+1, vector<int>(n+1)); // задаем размерность матрицы смежностей
    used.resize(n+1, false); // заполняем массив значением указывающим, что данная вершина не посещена

    // заполняем матрицу смежностей
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>g[i][j];
        }
    }

    vector<vector<int> > ans;// массив компонент связности

    for(int i=0;i<n;++i){
        if(!used[i]){
            vector<int>res;
            dfs(i, res);
            sort(res.begin(),res.end());
            ans.push_back(res);
        }
    }

    cout << ans.size() << endl;

    for(auto arr : ans){
        for(auto el : arr){
            cout << el + 1 << ' ';
        }
        cout << endl;
    }




}
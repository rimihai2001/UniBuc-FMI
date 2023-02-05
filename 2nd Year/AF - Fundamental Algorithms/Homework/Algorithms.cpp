#include <bits/stdc++.h>
using namespace std;

#define NMaxNoduri 100001
#define NMaxNoduri2 50005
#define INFINIT 0x3f3f3f3f



ifstream fin("data.in");
ofstream fout("data.out");

class Clasa_Graf
{
    int n, m;
    vector<int> lista_adiacenta[NMaxNoduri];

public:
    Clasa_Graf();
    ~Clasa_Graf();
    void dfs(int x,unordered_map<int,bool>& vector_vizitat);
    void bfs(int x,unordered_map<int,bool>& vector_vizitat,list<int>& coada_bfs);
    void sortare_topologica(int x,unordered_map<int,bool>& vector_vizitat,deque<int>& lista_sorttop);
    void DFS1(int x, unordered_map<int,bool>& vector_vizitat, vector<int>& stiva);
    void DFS2(int x, int nrctc, unordered_map<int,bool>& , vector<int>& , vector<int>& );
    void biconex(int start, int tp, unordered_map<int,int>& vizitat, int low[NMaxNoduri], stack<pair<int, int>>& stackCBC, vector <set <int>>& componentebcnx);
    void dfs_muchie_critica(int curr, int prev,int time, int disc[NMaxNoduri], int low2[NMaxNoduri], vector<vector<int>>& ans);
    bool HH(vector<int> grade);
    int find_node(int x, int par[]);
    void unite(int x,int y, int par[], int dim[]);
    void DFS_darb(int curr, int vizitat[], int& dist_max, int& nod_departe);
    void infoarena_dfs();
    void infoarena_bfs();
    void infoarena_sortaret();
    void infoarena_ctc();
    void infoarena_biconex();
    void leetcode_muchiecritica();
    void havelhakimi();
    void infoarena_dijkstra();
    void infoarena_bellman_ford();
    void infoarena_pmd();
    void infoarena_apm();
    void infoarena_roy_floyd();
    void infoarena_darb();
};

Clasa_Graf::Clasa_Graf()
{
    n=0;
    m=0;
}

Clasa_Graf::~Clasa_Graf()
{
    delete[] lista_adiacenta;
}

void Clasa_Graf::dfs(int x, unordered_map<int,bool>& vector_vizitat)
{
    vector_vizitat[x] = true;
    for (int i=0; i<lista_adiacenta[x].size(); ++i)
        if (vector_vizitat[lista_adiacenta[x][i]]==0)
            dfs(lista_adiacenta[x][i],vector_vizitat);
}

void Clasa_Graf::bfs(int x, unordered_map<int,bool>& vector_vizitat, list<int>& coada_bfs)
{
    int distanta_minima[NMaxNoduri];
    memset(distanta_minima,-1, sizeof(distanta_minima));
    vector_vizitat[x]=true;
    coada_bfs.push_back(x);
    distanta_minima[x]=0;
    while(!coada_bfs.empty())
    {
        x = coada_bfs.front();
        coada_bfs.pop_front();
        for (int i=0; i<lista_adiacenta[x].size(); ++i)
        {
            if (distanta_minima[lista_adiacenta[x][i]]<0)
            {
                vector_vizitat[lista_adiacenta[x][i]] = true;
                coada_bfs.push_back(lista_adiacenta[x][i]);
                distanta_minima[lista_adiacenta[x][i]]=distanta_minima[x]+1;
            }
        }
    }
    for(int i=1; i<=n; i++)
        fout<<distanta_minima[i]<<" ";
}

void Clasa_Graf::sortare_topologica(int x, unordered_map<int,bool>& vector_vizitat,deque<int>& lista_sorttop)
{
    vector_vizitat[x]=1;
    for(int i : lista_adiacenta[x])
    {
        if(vector_vizitat[i]==0)
            sortare_topologica(i,vector_vizitat,lista_sorttop);
    }
    lista_sorttop.push_front(x);
}

void Clasa_Graf::biconex(int start, int tp, unordered_map<int,int>& vizitat, int low[NMaxNoduri], stack<pair<int, int>>& stackCBC, vector <set <int>>& componentebcnx)
{
    int timp=tp+1;
    vizitat[start] = timp;
    low[start] = timp;
    for (int i=0; i<lista_adiacenta[start].size(); i++)
    {
        if (vizitat[lista_adiacenta[start][i]]==0)
        {
            stackCBC.push({start, lista_adiacenta[start][i]});
            biconex(lista_adiacenta[start][i],tp+1, vizitat, low, stackCBC, componentebcnx);
            low[start] = min(low[lista_adiacenta[start][i]],low[start]);
            if (low[lista_adiacenta[start][i]]>=vizitat[start])
            {
                set<int> elem;
                int elem1,elem2;
                elem1 = stackCBC.top().first;
                elem2 = stackCBC.top().second;
                elem.insert(elem1);
                elem.insert(elem2);
                stackCBC.pop();
                while (elem1 != start || elem2 != lista_adiacenta[start][i])
                {
                    elem1 = stackCBC.top().first;
                    elem2 = stackCBC.top().second;
                    elem.insert(elem1);
                    elem.insert(elem2);
                    stackCBC.pop();
                }
                componentebcnx.push_back(elem);
            }
        }
        else
        {
            low[start] = min(vizitat[lista_adiacenta[start][i]],low[start]);
        }
    }
}

void Clasa_Graf::dfs_muchie_critica(int curr, int prev,int time, int disc[NMaxNoduri], int low2[NMaxNoduri], vector<vector<int>>& ans)
{
    disc[curr] = ++time;
    low2[curr] = time;
    for (int i=0; i<lista_adiacenta[curr].size(); i++)
    {
        if (disc[lista_adiacenta[curr][i]] == 0)
        {
            dfs_muchie_critica(lista_adiacenta[curr][i], curr, time, disc, low2,ans);
            low2[curr] = min(low2[curr], low2[lista_adiacenta[curr][i]]);
        }
        else if (lista_adiacenta[curr][i] != prev)
        {
            low2[curr] = min(low2[curr], disc[lista_adiacenta[curr][i]]);
        }
        if (low2[lista_adiacenta[curr][i]] > disc[curr])
            ans.push_back({curr, lista_adiacenta[curr][i]});
    }
}

bool Clasa_Graf::HH(vector<int> grade)
{
    while (true)
    {
        sort(grade.begin(), grade.end());
        reverse(grade.begin(), grade.end());
        if (grade[0] == 0)
            return true;

        int nodactual=grade[0];
        grade.erase(grade.begin() + 0);

        if (grade.size() < nodactual)
            return false;

        for (int i=0; i<nodactual; i++)
        {
            grade[i]--;
            if (grade[i] < 0)
                return false;
        }
    }
}


int Clasa_Graf::find_node(int x, int par[])
{
    while(x!=par[x])
        x=par[x];
    return x;
}

void Clasa_Graf::unite(int x,int y,int par[], int dim[])
{
    int find_x=find_node(x, par);
    int find_y=find_node(y, par);
    if(dim[find_x]>=dim[find_y])
    {
        par[find_y]=find_x;
        dim[find_x]+=dim[find_y];
    }
    else
    {
        par[find_x]=find_y;
        dim[find_y]+=dim[find_x];
    }
}


void Clasa_Graf::DFS_darb(int curr, int vizitat[], int& dist_max, int& nod_departe)
{
    for(int i = 0; i < lista_adiacenta[curr].size(); i++)
    {
        if(vizitat[lista_adiacenta[curr][i]] == 0)
        {
            vizitat[lista_adiacenta[curr][i]]=vizitat[curr];
            vizitat[lista_adiacenta[curr][i]]++;
            if(vizitat[lista_adiacenta[curr][i]] > dist_max)
            {
                nod_departe = lista_adiacenta[curr][i];
                dist_max=vizitat[lista_adiacenta[curr][i]];
            }
            DFS_darb(lista_adiacenta[curr][i], vizitat, dist_max, nod_departe);
        }
    }
}

void Clasa_Graf::infoarena_dfs()
{
    int comp_conexe=0;
    unordered_map<int,bool> vector_vizitat;
    fin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int a,b;
        fin>>a>>b;
        lista_adiacenta[a].push_back(b);
        lista_adiacenta[b].push_back(a);
    }
    dfs(1,vector_vizitat);
    comp_conexe=1;
    for(int i=2; i<=n; i++)
        if(vector_vizitat[i] == 0)
        {
            dfs(i,vector_vizitat);
            comp_conexe++;
        }
    fout<<comp_conexe;
}

void Clasa_Graf::infoarena_bfs()
{
    int st;
    unordered_map<int,bool> vector_vizitat;
    list<int> coada_bfs;
    fin>>n>>m>>st;
    for(int i=1; i<=m; i++)
    {
        int a,b;
        fin>>a>>b;
        lista_adiacenta[a].push_back(b);
    }
    bfs(st,vector_vizitat,coada_bfs);
}

void Clasa_Graf::infoarena_sortaret()
{
    unordered_map<int,bool> vector_vizitat;
    deque<int> lista_sorttop;
    fin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int a,b;
        fin>>a>>b;
        lista_adiacenta[a].push_back(b);
    }
    for(int i=n; i>=1; i--)
    {
        if(vector_vizitat[i]==0)
            sortare_topologica(i,vector_vizitat,lista_sorttop);
    }
    while(!lista_sorttop.empty())
    {
        int x=lista_sorttop.front();
        fout<<x<<" ";
        lista_sorttop.pop_front();
    }
}

void Clasa_Graf::infoarena_biconex()
{
    fin>>n>>m;
    unordered_map<int,int> vizitat;
    int low[NMaxNoduri]= {0};
    stack<pair<int, int>> stackCBC;
    vector <set <int>> componentebcnx;

    for(int i=1; i<=m; i++)
    {
        int x,y;
        fin>>x>>y;
        lista_adiacenta[x].push_back(y);
        lista_adiacenta[y].push_back(x);
    }
    biconex(1,0,vizitat,low,stackCBC,componentebcnx);
    fout<< componentebcnx.size() <<'\n';

    for (auto cbc: componentebcnx)
    {
        set<int>::iterator it;
        for (it = cbc.begin(); it != cbc.end(); it++)
            fout << *it << " ";
        fout << "\n";
    }
}

void Clasa_Graf::leetcode_muchiecritica()
{
    int disc[NMaxNoduri]= {0};
    int low2[NMaxNoduri]= {0};
    vector<vector<int>> ans;
    fin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int x,y;
        fin>>x>>y;
        lista_adiacenta[x].push_back(y);
        lista_adiacenta[y].push_back(x);
    }
    dfs_muchie_critica(0, -1, 0,disc,low2,ans);
    for(int i=0; i<ans.size(); i++)
        fout<<ans[i][0]<<" "<<ans[i][1]<<'\n';
}

void Clasa_Graf::havelhakimi()
{
    fin>>n;
    vector<int> grade;
    for(int i=1; i<=n; i++)
    {
        int x;
        fin>>x;
        grade.push_back(x);
    }
    if(HH(grade)==true) fout<<"Graf valid"<<'\n';
    else fout<<"Graf imposibil"<<'\n';
}

void Clasa_Graf::infoarena_dijkstra()
{
    vector<pair<int,int>> g[NMaxNoduri2];
    bool viz[NMaxNoduri2];
    int d[NMaxNoduri2];

    int n,m;
    fin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int a,b,cost;
        fin>>a>>b>>cost;
        g[a].push_back({b,cost});
    }

    for(int i=1; i<=n; i++)
        d[i]=INFINIT;

    d[1]=0;
    priority_queue<pair<int,int>> q;
    q.push({0,1});
    while(!q.empty())
    {
        int nod=q.top().second;
        q.pop();
        if(viz[nod]==true) continue;
        else viz[nod]=true;
        for(auto vecin : g[nod])
        {
            if(d[nod]+vecin.second<d[vecin.first])
            {
                d[vecin.first]=d[nod]+vecin.second;
                q.push({-d[vecin.first],vecin.first});
            }
        }
    }

    for(int i=2; i<=n; i++)
        if(d[i]!=INFINIT)fout<<d[i]<<" ";
        else fout<<0<<" ";
}

void Clasa_Graf::infoarena_bellman_ford()
{
    vector<pair<int,int>> g[NMaxNoduri2];
    bool viz[NMaxNoduri2];
    int d[NMaxNoduri2];
    int ok=1;

    int n,m;
    fin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int a,b,cost;
        fin>>a>>b>>cost;
        g[a].push_back({b,cost});
    }

    for(int i=1; i<=n; i++)
        d[i]=INFINIT;

    d[1]=0;
    priority_queue<pair<int,int>> q;
    q.push({0,1});
    while(!q.empty())
    {

        int nod=q.top().second;
        viz[nod]++;
        if(viz[nod]>=n)
        {
            fout<<"Ciclu negativ!";
            ok=0;
            return;
        }
        q.pop();
        for(auto vecin : g[nod])
        {
            if(d[nod]+vecin.second<d[vecin.first])
            {
                d[vecin.first]=d[nod]+vecin.second;
                q.push({-d[vecin.first],vecin.first});
            }
        }
    }
    if(ok==1)
        for(int i=2; i<=n; i++)
            if(d[i]!=INFINIT)fout<<d[i]<<" ";
            else fout<<0<<" ";
}

void Clasa_Graf::infoarena_pmd()
{
    int par[NMaxNoduri];
    int dim[NMaxNoduri];
    int n,m;
    fin>>n>>m;
    for(int i=1; i<=n; ++i)
    {
        par[i]=i;
        dim[i]=1;
    }
    for(int i=1; i<=m; i++)
    {
        int optiune, a, b;
        fin>>optiune>>a>>b;
        if(optiune == 1)
        {
            unite(a,b,par,dim);
        }
        else if(optiune==2)
        {
            if(find_node(a,par) == find_node(b,par))
                fout<<"DA";
            else
                fout<<"NU";
            fout<<'\n';
        }
    }
}


void Clasa_Graf::infoarena_apm()
{
    vector<pair<int,pair<int,int>>> muchii;
    vector<pair<int,int>> sol_m;
    int par[NMaxNoduri];
    int dim[NMaxNoduri];
    int n,m;
    fin>>n>>m;
    for(int i=1; i<=n; ++i)
    {
        par[i]=i;
        dim[i]=1;
    }
    for(int i=1; i<=m; i++)
    {
        int a,b,cost;
        fin>>a>>b>>cost;
        muchii.push_back({cost,{a,b}});
    }
    int cost = 0;
    sort(muchii.begin(), muchii.end());
    for(auto muchie : muchii)
    {
        if(find_node(muchie.second.first, par) != find_node(muchie.second.second, par))
        {
            unite(muchie.second.first, muchie.second.second, par, dim);
            cost += muchie.first;
            sol_m.push_back({muchie.second.first, muchie.second.second});
        }
    }
    fout<<cost<<"\n";
    fout<<sol_m.size()<<"\n";
    for(int i=0; i<sol_m.size(); i++)
        fout<<sol_m[i].first<<" "<<sol_m[i].second<<'\n';
}

void Clasa_Graf::infoarena_roy_floyd()
{
    int m[105][105];
    int n;
    fin>>n;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            fin>>m[i][j];
            if(m[i][j]==0) m[i][j]=INFINIT;
        }

    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(m[i][k]!=INFINIT and m[k][j]!=INFINIT and m[i][j]>m[i][k]+m[k][j])
                    m[i][j]=m[i][k]+m[k][j];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i!=j and m[i][j]!=INFINIT) fout<<m[i][j]<<" ";
            else fout<<"0 ";
            if(j==n) fout<<'\n';
        }
    }
}

void Clasa_Graf::infoarena_darb()
{
    int vizitat[NMaxNoduri];
    int dist_max, nod_departe;
    dist_max=0;
    nod_departe=0;
    int n;
    fin>>n;
    for(int i=1; i<=n-1; i++)
    {
        int a,b;
        fin>>a>>b;
        lista_adiacenta[a].push_back(b);
        lista_adiacenta[b].push_back(a);
    }
    vizitat[1]=1;
    DFS_darb(1, vizitat, dist_max, nod_departe);
    dist_max = 0;
    memset(vizitat,0,sizeof(vizitat));
    vizitat[nod_departe] = 1;
    DFS_darb(nod_departe, vizitat, dist_max, nod_departe);
    fout <<dist_max;
}

int main()
{
    Clasa_Graf g;
    //g.infoarena_dfs();
    //g.infoarena_bfs();
    //g.infoarena_sortaret();
    //g.infoarena_biconex();
    //g.leetcode_muchiecritica();
    //g.havelhakimi();
    //g.infoarena_dijkstra();
    //g.infoarena_bellman_ford();
    //g.infoarena_pmd();
    //g.infoarena_apm();
    //g.infoarena_roy_floyd();
    g.infoarena_darb();
    return 0;
}

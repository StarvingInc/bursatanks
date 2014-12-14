typedef void(* fgen)(int,&vector<vector<int>>)
void ex_generator(int seed, std::vector<std::vector<int> > &tab)
{
    srand(seed);
    for(int i = 0;i<tab.size();++i)
    {
        for(int j = 0;j<tab[0].size();++j)
        {
            tab[i][j] = rand()%2;
        }
    }
    std::vector<std::vector<int> > temp(tab);
    for(int i = 0;i<7;++i)
    {
        for(int i = 1;i<tab.size()-1;++i)
        {
            for(int j = 1;j<tab[0].size()-1;++j)
            {
                temp[i][j]  =0;
                temp[i][j] +=tab[i-1][j-1];
                temp[i][j] +=tab[i-1][j  ];
                temp[i][j] +=tab[i-1][j+1];
                temp[i][j] +=tab[i  ][j-1];
                temp[i][j] +=tab[i  ][j  ];
                temp[i][j] +=tab[i  ][j+1];
                temp[i][j] +=tab[i+1][j-1];
                temp[i][j] +=tab[i+1][j  ];
                temp[i][j] +=tab[i+1][j+1];
            }
        }
        for(int i = 1;i<tab.size()-1;++i)
        {
            for(int j = 1;j<tab[0].size()-1;++j)
            {
                if(temp[i][j] > 12) tab[i][j] = 3;
                else if(temp[i][j] > 7) tab[i][j] = 2;
                else if(temp[i][j] > 5) tab[i][j] = 1;
                else tab[i][j] = 0;
            }
        }
    }
}
class Area
{
    vector<vector<int>> tab;
    int x_dim;
    int y_dim;
    public:
        bool generate(int x,int y,int seed,fgen gen = ex_generator) ///It's generating map.
        {
            x_dim = x;
            y_dim = y;
            tab.resize(y_dim);
            for(int i = 0;i<y_dim;++i)
            {
                tab[i].resize(x_dim);
            }
            gen(seed,tab)
            return true;
        }
}

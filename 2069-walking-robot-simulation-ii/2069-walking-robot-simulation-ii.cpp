class Robot {
public:
    int x=0,y=0;
    pair<int,int> dir={1,0};
    vector<pair<int,int>> v={{1,0},{0,1},{-1,0},{0,-1}};
    int w,h;
    Robot(int width, int height) {
        w=width;
        h=height;
    }
    
    void step(int num) {
        int cycle=2*(w+h-2);
        if(cycle==0) return;
        while(num>0)
        {   num=num%cycle;
            if(num==0) num=cycle;
            int nx=x+dir.first;
            int ny=y+dir.second;
            if(nx>=w || ny >=h || nx<0 || ny<0)
            {
                nx-=dir.first;
                ny-=dir.second;
                dir={-dir.second,dir.first};
                num++;
            }
            x=nx;
            y=ny;
            num--;
        }
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        if(dir==v[0]) return "East";
        else if(dir==v[1]) return "North";
        else if(dir==v[2]) return "West";
        else return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
#include<iostream>
using namespace std;
typedef struct point{
    int x,y;
}point;
int direction(point p1,point p2,point p3){
    int ans=((p2.y-p1.y)*(p3.x-p2.x))-((p2.x-p1.x)*(p3.y-p2.y));
    if(ans==0){
        return 0; //collinear
    }
    return (ans>0)?1:2; //1 for clock    2 for counter
}
bool onsegment(point p1,point p2,point p3){
    if((p2.x<=max(p1.x,p3.x)&&p2.x>=min(p1.x,p3.x)) && (p2.y<=max(p1.y,p3.y)&&p2.y>=min(p1.y,p3.y))){
        return true;
    }
    return false;
}
bool dointersect(point p1,point p2,point p3,point p4){
    int d1=direction(p3,p4,p1);
    int d2=direction(p3,p4,p2);
    int d3=direction(p1,p2,p3);
    int d4=direction(p1,p2,p4);
    if(d1!=d2 && d3!=d4){
        return true;
    }
    if(d1==0){
        return onsegment(p3,p4,p1);
    }
    if(d2==0){
        return onsegment(p3,p4,p2);
    }
    if(d3==0){
        return onsegment(p1,p2,p3);
    }
    if(d4==0){
        return onsegment(p1,p2,p4);
    }
    return false;
}
int main(){
    int n=4;
    point arr[4];
    int x,y;
    for(int i=0;i<4;i++){
        cin>>x;
        cin>>y;
        arr[i].x=x;
        arr[i].y=y;
    }
    cout<<dointersect(arr[0],arr[1],arr[2],arr[3]);
}

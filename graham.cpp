#include<iostream>
#include<stack>
using namespace std;
typedef struct point{
    int x,y;
}point;
point p0;
point nexttotop(stack<point>&s){
    point p=s.top();
    s.pop();
    point nex=s.top();
    s.push(p);
    return nex;
}
void swap(point &p1,point &p2){
    point p=p1;
    p1=p2;
    p2=p;
}
int distsq(point p1,point p2){
    int val=((p1.x-p2.x)*(p1.x-p2.x))+((p1.y-p2.y)*(p1.y-p2.y));
    return val;
}
int orientation(point p1,point p2,point p3){
    int val=(p2.y-p1.y)*(p3.x-p2.x)-(p2.x-p1.x)*(p3.y-p2.y);
    if(val==0){
        return 0;
    }
    return (val>0)?1:2;
}
int compare(const void *vp1,const void *vp2){
    point *p1=(point*)vp1;
    point *p2=(point*)vp2;
    int o=orientation(p0,*p1,*p2);
    if(o==0){
        return (distsq(p0,*p2)>=distsq(p0,*p1))?-1:1;
    }
    return (o==2)?-1:1;
}
void convexhull(point points[],int n){
    int ymin=points[0].y,min=0;
    for(int i=1;i<n;i++){
        int y=points[i].y;
        if((y<ymin)||(ymin==y && points[i].x<points[min].x)){
            ymin=points[i].y;
            min=i;
        }
    }
    swap(points[0],points[min]);
    p0=points[0];
    qsort(&points[1],n-1,sizeof(point),compare);
    int m=1;
    for(int i=1;i<n;i++){
        while(i<n-1 && orientation(p0,points[i],points[i+1])==0){
            i++;
        }
        points[m]=points[i];
        m++;
    }
    if(m<3){
        return;
    }
    stack<point>s;
    s.push(points[0]);
    s.push(points[1]);
    s.push(points[2]);
    for(int i=3;i<m;i++){
        while(s.size()>1 && orientation(nexttotop(s),s.top(),points[i])!=2){
            s.pop();
        }
        s.push(points[i]);
    }
    while(!s.empty()){
        point p=s.top();
        cout<<p.x<<" "<<p.y<<endl;
        s.pop();
    }
}
int main(){
    point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
                      {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    int n=sizeof(points)/sizeof(points[0]);
    convexhull(points,n);
}
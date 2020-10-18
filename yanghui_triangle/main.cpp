#include <queue>

using namespace std;
void yanghui_triangle(const int n){
    queue<int> q;
    q.push(1);
    for(int i=0;i<=n;i++){
        int s=0;
        q.push(s);
        for(int j=0;j<i+2;j++){
            int t;
            int tmp;
            t = q.front();
            q.pop();
            tmp = s+t;
            q.push(tmp);
            s=t;
            if(j!= i+1){
                printf("%d", s);
            }
        }
        printf("\n");
    }
}

int main(){
    yanghui_triangle(5);
    return 0;
}
#include<bits/stdc++.h>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("�Ŵ����η���in.txt", "r", stdin);
FILE *fout = freopen("�Ŵ����η���out.txt", "w", stdout);
#endif 
using namespace std;
unordered_map<char,string>toBinary={//16����ת2����
    {'0',"0000"}, {'1',"0001"}, {'2',"0010"}, {'3',"0011"},
    {'4',"0100"}, {'5',"0101"}, {'6',"0110"}, {'7',"0111"},
    {'8',"1000"}, {'9',"1001"}, {'a',"1010"}, {'b',"1011"},
    {'c',"1100"}, {'d',"1101"}, {'e',"1110"}, {'f',"1111"}
};
unordered_map<int,char>toAns={{1,'A'},{3,'J'},{5,'D'},{4,'S'},{0,'W'},{2,'K'}};//�׶�������Ӧ���ַ�
int H,W,direction[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
vector<string>g;//�洢����ͼ
void DFS(int i,int j,char c,int&ans){//��graph[i][j]λ�ÿ�ʼ�����������,c��ʾ��ǰ��������0����1�ַ�,ans��ʾ�׶�����
    g[i][j]=(char)(c+2);//0�ַ����2,1�ַ����3
    for(int k=0;k<4;++k){//����4����Χ���ַ�
        int ii=i+direction[k][0],jj=j+direction[k][1];
        if(ii>=0&&ii<g.size()&&jj>=0&&jj<g[i].size()){//�����һ��λ��û��Խ��
            if(c=='1'&&g[ii][jj]=='0'){//��ǰλ����1�ַ�������һ��λ����0�ַ�
                ++ans;//�����׶�����
                DFS(ii,jj,'0',ans);//����һ��λ�ÿ�ʼ����0�ַ�
            }
            if(g[ii][jj]==c)//��һ��λ���뵱ǰλ���ַ���ͬ
                DFS(ii,jj,c,ans);//��������
        }
    }
}
int main(){
    for(int ii=1;~scanf("%d%d%*c",&H,&W)&&H!=0;++ii){
        g.resize(H+2);
        g.front()=string(W*4+2,'0');//��һ��ױ�
        for(int i=1;i<=H;++i){//��ȡ����
            g[i]="0";//��һ��ױ�
            string s;
            getline(cin,s);
            for(char c:s)
                g[i]+=toBinary[c];
            g[i]+="0";//��һ��ױ�
        }
        g.back()=string(W*4+2,'0');//��һ��ױ�
        
        
			cout<<g.size()<<endl; 
			cout<<g[1].size()<<endl;
        int ans=0;
        string result="";//���ս��
        DFS(0,0,'0',ans);
        for(int i=0;i<g.size();++i)
            for(int j=0;j<g[i].size();++j){
                if(g[i][j]=='1'){
                    ans=0;
                    DFS(i,j,'1',ans);
                    result+=toAns[ans];
                }
            }
        sort(result.begin(),result.end());//���ֵ�������
        printf("Case %d: %s\n",ii,result.c_str());//���
    }
    return 0;
}

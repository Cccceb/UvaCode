#include<bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;
int main() {
	string name;
	cin >> name;
	freopen((name + ".cpp").c_str(),"w",stdout);
	cout << "#include<bits/stdc++.h>\n#pragma warning(disable:4996)\n#define LOCAL\n#ifdef LOCAL"
		<< "\nFILE *fin = freopen(\"" << name << "in.txt\", \"r\", stdin);\n"
		<< "FILE *fout = freopen(\"" << name << "out.txt\", \"w\", stdout);\n"
		<< "#endif\nusing namespace std; ";


		
	

	fopen((name + "in.txt").c_str(),"w");
	fopen((name + "out.txt").c_str(),"w");
}

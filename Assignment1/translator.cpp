#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string.h>
#include <limits.h>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <numeric>
#include <algorithm>

/* Macros start */
#define MAX(a,b)         	((a < b) ?  (b) : (a))
#define BIGGEST(a,b,c)   	((MAX(a,b) < c) ?  (c) : (MAX(a,b)))
#define MIN(a,b)         	((a < b) ?  (a) : (b))
#define LEAST(a,b,c)		((MIN(a,b) < c) ? (MIN(a,b)) : (c))
#define RESET(arr, value) 	memset(arr, value, sizeof(arr)) //Remember, value can be {0,-1}
#define ALL(v) 			 	(v).begin(), (v).end()
#define SZ(v) 			 	((int)(v).size())
#define DREP(a)             sort(all(a)); a.erase(unique(all(a)),a.end())
#define FOR(c,it) 			for(typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define RFOR(c,rit) 		for(typeof((c).rbegin()) rit = (c).rbegin(); rit != (c).rend(); rit++)
#define MAXSIZE 100
/* Macros end */

using namespace std;
/* Typedefs*/
typedef long long 					ll;
typedef unsigned long long 			ull;
typedef pair<int, int> 				ii;
typedef vector<int> 				vi;
typedef vector<ii> 					vii;
typedef vector<vi> 					vvi;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	while(1) {
		getline(cin, s);
		if(cin.fail()) break;
		if((s[1] == 'a' && s[2] == 'n' && s[3] == 'd') || (s[1] == 's' && s[2] == 'u' && s[3] == 'b')) {
			continue;
		}
		else if(s[1] == 'l' && s[2] == 'e') {
			getline(cin, s);
			getline(cin, s);
			s = "\tpopq	%rbp\n\t.cfi_def_cfa 7, 8\n";
		}else if(s == "\tpushl\t%ebp") s = "\tpushq\t%rbp";
		else if(s == "\tmovl\t%esp, %ebp") s = "\tmovq\t%rsp, %rbp";
		else if(s == "\tmovl\t$.LC0, (%esp)") s = "\tmovl\t$.LC0, %edi";
		else {
			for(int i = 0; i < SZ(s) ; i++){
				if(s[i] == '5') s[i] = '6';
				if(s[i] == '8') {
					s[i] = '1';
					s = s+"6";
				}
				if(s[i] == 'e' && s[i-1] == '%') s[i] = 'r';
				if(s[i] == 'r' && s[i-1] == '%') s[i] = 'e';
			}
		}
		cout << s << '\n';
	}
	return 0;
}
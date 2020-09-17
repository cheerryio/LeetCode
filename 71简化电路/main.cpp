
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>
#include <sstream>
#include <map>
#include <numeric>
#include <list>

using namespace std;

/*
* 以 Unix 风格给出一个文件的绝对路径，你需要简化它。或者换句话说，将其转换为规范路径。
在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；此外，两个点 （..） 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。更多信息请参阅：Linux / Unix中的绝对路径 vs 相对路径
请注意，返回的规范路径必须始终以斜杠 / 开头，并且两个目录名之间必须只有一个斜杠 /。最后一个目录名（如果存在）不能以 / 结尾。此外，规范路径必须是表示绝对路径的最短字符串。

示例 1：

输入："/home/"
输出："/home"
解释：注意，最后一个目录名后面没有斜杠。
示例 2：

输入："/../"
输出："/"
解释：从根目录向上一级是不可行的，因为根是你可以到达的最高级。
示例 3：

输入："/home//foo/"
输出："/home/foo"
解释：在规范路径中，多个连续斜杠需要用一个斜杠替换。
示例 4：

输入："/a/./b/../../c/"
输出："/c"
示例 5：

输入："/a/../../b/../c//.//"
输出："/c"
示例 6：

输入："/a//b////c/d//././/.."
输出："/a/b/c"

*/

class Solution {
private:
	map<string, int> m = {
		{".",1},
		{"..",2}
	};

	/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	* 这个函数有个点就是我用   i！=path.end() 进行比较会报错！！！
	* 只有把path.end()当作参数传入这个函数才能用!!!!!
	*/
	string read(string path,string::iterator &i,string::iterator &end) {
		string r;
		while (i != path.end() && *i != '/') {
			r.push_back(*i);
			i++;
		}
		if (r.size() == 0)
			i++;
		return r;
	}

	int classify(string content) {
		if (content.empty())
			return 4;
		if (content.find('/')!=string::npos)
			return 5;
		auto search = m.find(content);
		if (search != m.end())
			return search->second;
		return 3;
	}
public:
	/*
	* 函数可能会读到目录名(由字母组成)，'/'，'.'，'..'，无效字符
	* 读到目录名，加入list后面。读到'.'不做处理。读到'..'list末尾元素出来。
	* 从list还原绝对路径，从前往后遍历，注意加'/'
	* 
	* 
	* 
	* OK 这里好像发现了更简单的方法.....直接用   '/'去split一下再做......
	* 
	*/
	string simplifyPath(string path) {
		list<string> l;
		int val = 0;
		string content;
		string::iterator i = path.begin();
		string::iterator end = path.end();
		while (i != path.end()) {
			content = read(path, i,end);
			val = classify(content);
			switch (val) {
			case 1:
				break;
			case 2:
				if (!l.empty())
					l.pop_back();
				break;
			case 3:
				l.push_back(content);
				break;
			case 4:case 5:
				break;
			default:
				break;
			}
		}
		string r;
		for (list<string>::iterator i = l.begin(); i != l.end(); i++) {
			r.push_back('/');
			r.insert(r.size(),*i);
		}
		if (l.empty())
			r.push_back('/');
		return r;
    }
};

int main() {
	Solution a;
	string path = a.simplifyPath(string("/a//b////c/d//././/.."));
	cout << path << endl;
	return 0;
}

#include <iostream>
#include <stack>
using namespace std;
int PolishRecord(const string& line) {
	stack<int> num;
	for (int i = 0; i < line.size(); i++)
	{
		if (isdigit(line[i])) { num.push(line[i] - '0'); }
		else 
		{
			int b = num.top();
			num.pop();
			int a = num.top();
			num.pop();
			if (line[i] == '+') {
				num.push(a + b);
			}
			else if (line[i] == '-')
			{
				num.push(a - b);
			}
			else if (line[i] == '*')
			{
				num.push(a * b);
			}
			else if (line[i] == '/')
			{
				num.push(a / b);
			}
		}
	}

	return num.top();
}
int main()
{
	cout << PolishRecord("825*+132*+4-/") << endl;
}

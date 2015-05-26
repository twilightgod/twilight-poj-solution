#include<iostream>
#include<stack>
using namespace std;

bool god;
stack<int> s;
int acc;

int main()
{
	//freopen("in.txt","r",stdin);
	while(1)
	{
		while(s.size())
		{
			s.pop();
		}
		god=false;

		while(1)
		{
			int tmp;
			if(scanf("%d",&tmp)==EOF)
			{
				return 0;
			}
			if(!god)
			{
				if(tmp<0)
				{
					s.push(tmp);
				}
				else
				{
					acc=0;
					while(s.size()&&s.top()!=-tmp)
					{
						acc+=-s.top();
						s.pop();
					}
					if(s.empty()||acc>=-s.top())
					{
						god=true;
					}
				}
			}
			if(getchar()=='\n')
			{
				if(s.size()!=1)
				{
					god=true;
				}
				break;
			}
		}
		printf(":-%s\n",god?"( Try again.":") Matrioshka!");
	}
	return 0;
}

#include <iostream>
#include <string>

using namespace std;

class Debug{
	public:
		int factorial(int n) // find a factorial of a number
		{
			int i=1,sol=1;
			while(i<=n)
			{
				sol=sol*i;
//				i--;
                i++; // sol
			}
			return sol;
		}


		void helloWorld10Times() // hello world 10 times
		{
			for(int i=0;i<10;i++) // sol
//            for(int i=0;i<10;i++);
				cout<<"hello, world!!!"<<endl;
		}

        // Determine circle Area
        //sol
        double circleArea(double radius)
        {
            // Test with radius = 10000000000000000000000000000000
            double pi=3.14159265358979323846;
            double ans = pi*radius*radius;
            return ans;
        }

//		void swap2(int *x,int *y){
////            //sol
////            int t = *x;
////            *x = *y;
////            *y = t;
//		}
//
//		void sort3numbers(int *x,int *y,int *z) // Sort 3 numbers with pointers
//		{
//			if(*x > *y)
//		        swap2(x, y);
//		    if(*x > *z)
//		        swap2(x, z);
//		    if(*y > *z)
//		        swap2(y, z);
//
//		  	cout<<"The numbers in ascending order: "<<(*x)<<" "<<(*y)<<" "<<(*z)<<endl;
//		}

		double averageOfNumbers() // Average of an array
		{
			int array[]={3,1,2,3,4,5,7};

			int sol=0;
			for(int i=0;i<7;i++)
				sol=sol+array[i];

            float ans = sol/7.0; // sol
            return ans;
		}

		bool palindromeProblem(string cadena) // Palindrome Problem
		{
			int start=0,end=cadena.length()-1;
			bool flag=true;
			while(start<=end && flag==true)
				if(cadena[start]!= cadena[end])
					flag=false;
				else
				{
                    //sol
                    start++;
                    end--;
				}
			return flag;
		}

//		int countVowels(string str) // count all the vowels in a given string.
//		{
//			int count=0;
//			char vowels[10]={'a','e','i','o','u','A','E','I','O','U'};
//          for(int i=0;i<str.length()-1;i++)//sol
//			{
//				bool flag=true;
//				for (int j=0;j<10;j++)
//					if(str[i]==vowels[j])
//					{
//						flag=false;
//						count++;
//					}
//			}
//			return count;
//		}
//};


int main()
{
	Debug test;
	int n,a,b,c;
	double radius;

	cout<<endl<<"[Problem_1: Factorial]"<<endl;
	cout<<"Enter a number:"<<endl;
	cin>>n;
	cout<<"The factorial of "<<n<<" is "<<test.factorial(n)<<endl;

//	cout<<endl<<"[Problem_2: Hello_world_n_times]"<<endl;
//	cout<<"Find the error!!!!!!!!!!!!!!!!!!!!!!!! "<<endl;
//	test.helloWorld10Times();

//	cout<<endl<<"[Problem_3: Circle Area]"<<endl;
//	cout<<"Enter the radio of the circle:"<<endl;
//	cin>>radius;
//	cout<<"The Area of the circle is "<<test.circleArea(radius)<<endl;

//	//sort 3 pointers
//	cout<<endl<<"[Problem_4: Sort 3 numbers with pointers]"<<endl;
//	cout<<"Enter 3 numbers please:"<<endl;
//	cin>>a>>b>>c;
//	test.sort3numbers(&a,&b,&c);

//	cout<<endl<<"[Problem_5: Average of numbers]"<<endl;
//	cout<<"We have the correspond array: 3,1,2,3,4,5. What is the average of its elements?"<<endl;
//	cout<<"Answer: "<<test.averageOfNumbers()<<endl;

//	cout<<endl<<"[Problem_6: Palindrome]"<<endl;
//    string cad="abccba";
//	if(test.palindromeProblem(cad))
//		cout<<cad<<" is a palindrome."<<endl;
//	else
//		cout<<cad<<" is not a palindrome."<<endl;

//	cout<<endl<<"[Problem_7: Count vowels in an string]"<<endl;
//	string cad="HELLO WORLD";
//	cout<<"We have "<< test.countVowels(cad)<<" vowels in ' "<<cad<<"'"<<endl;

	return 0;
}
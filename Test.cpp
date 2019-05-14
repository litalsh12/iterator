#include <iostream>
using namespace std;
#include "badkan.hpp"
#include "chain.hpp"
#include "powerset.hpp"
#include "product.hpp"
#include "range.hpp"
#include "zip.hpp"

using namespace itertools;

int main() {

	badkan::TestCase testcase;
	int grade = 0;
	int signal = setjmp(badkan::longjmp_buffer);
	int temp = 0;
	char tempc = 'a';

	if (signal == 0) {
	/////////////////////////My_Test///////////////////////////
	//range:
		testcase.setname("range test");
		 temp = 1;
		for (int i: range(1,10)) {
			testcase.CHECK_EQUAL(i, temp);
			temp++;
		}
		temp = 203;
		for (int i: range(203,210)) {
			testcase.CHECK_EQUAL(i, temp);
			temp++;
		}
		temp = -3;
		for (int i: range(-3,0)) {
			testcase.CHECK_EQUAL(i, temp);
			temp++;
		}
		temp = -20;
		for (int i: range(-20,4)) {
			testcase.CHECK_EQUAL(i, temp);
			temp++;
		}
		temp = 0;
		for (int i: range(0,0)) {
			testcase.CHECK_EQUAL(i, temp);
			temp++;
		}
		for (int i: range('a','z')) {
			testcase.CHECK_EQUAL(i, tempc);
			tempc++;
		}
		tempc = 'c';
		for (int i: range('c','e')) {
			testcase.CHECK_EQUAL(i, tempc);
			tempc++;
		}

		tempc = 'a';
		for (int i: range('a','a')) {
			testcase.CHECK_EQUAL(i, tempc);
			tempc++;
		}

    //Chain_Test:
		testcase.setname("Chain test");
		temp=0;
		int Check1[] = {1,2,3,4,5,6,7,8,9,10};
		for(int i: chain(range(1,6), range(5,11))) {
			testcase.CHECK_EQUAL(i, Check1[temp]);
			temp++;				
		}

		temp = 0;
		int Check2[] = {0,1,2,4,5,6,7};
		for(int i: chain(range(0,3), range(4,7))) {
			testcase.CHECK_EQUAL(i, Check2[temp]);
			temp++;				
		}

		temp = 0;
		char Check3[] = {'a','b','c','d'};
		for(int i: chain(range('a','b'), range('b','e'))) {
			testcase.CHECK_EQUAL(i, Check3[temp]);
			temp++;				
		}
		
		temp = 0;
		char Check4[] = {'h','i','j','L','M','N','O'};
		for(int i: chain(range('h','k'), range('L','P'))) {
			testcase.CHECK_EQUAL(i, Check4[temp]);
			temp++;				
		}
			temp = 0;
		char Check5[] = {'A','B','C','F','G','H'};
		
		for(int i: chain(range('A','D'), range('F','I')))
		{
			testcase.CHECK_EQUAL(i, Check5[temp]);
			temp++;				
		}

	
    //Product:
        testcase.setname(" TEST PRODUCT");
	    int temp=0;
		string Check6[]={"0,h","0,e","0,l","0,l","0,o","1,h","1,e","1,l","1,l","1,o","2,h","2,e","2,l","2,l","2,o"};
        for (auto pair: product(range(0,3), string("hello")))
        {
		testcase.CHECK_OUTPUT(pair,Check6[temp]);
		temp++;
        }
		
	    temp=0;
		string Check7[]={"0,3","0,4","1,3","1,4","2,3","2,4"};
        for (auto pair: product(range(0,3), range(3,5)))
        {
		testcase.CHECK_OUTPUT(pair,Check7[temp]);
		temp++;
        }
		
	    temp=0;
		string Check8[]={"h,1","h,2","h,3","h,4","e,1","e,2","e,3","e,4","l,1","l,2","l,3","l,4","l,1","l,2","l,3","l,4","o,1","o,2","o,3","o,4"};
        for (auto pair: product(string("hello"), range(1,5)))
        {
		testcase.CHECK_OUTPUT(pair,Check8[temp]);
		temp++;
        }
		temp=0;
		string Check9[]={"a,1","a,2","a,3","a,4","b,1","b,2","b,3","b,4","c,1","c,2","c,3","c,4","d,1","d,2","d,3","d,4","e,1","e,2","e,3","e,4"};
        for (auto pair: product(range('a','f'), range(1,5)))
        {
		testcase.CHECK_OUTPUT(pair,Check9[temp]);
		temp++;
        }
	    temp=0;
		string Check10[]={"a,d","a,e","a,f","a,g","a,h","b,d","b,e","b,f","b,g","b,h","c,d","c,e","c,f","c,g","c,h"};
        for (auto pair: product(range('a','d'), range('d','i')))
        {
		testcase.CHECK_OUTPUT(pair,Check10[temp]);
		temp++;
        }

     // Zip:
		testcase.setname("Test Zip ");
        temp=0;
        string Check11[]={"1,a","2,b","3,c","4,d"};
        for (auto pair: zip(range(1,5), range('a','e'))) {
		testcase.CHECK_OUTPUT(pair,Check11[temp]);
		temp++;
        }

        temp=0;
		string Check12[]={"n,o","a,r","o,e","m,l","i,r"};
        for (auto pair: zip(string("naomi"), string("orelr"))) {
		testcase.CHECK_OUTPUT(pair,Check12[temp]);
		temp++;
        }

        temp=0;
		string Check13[]={"0,7","1,8","2,9","3,10","4,11"};
        for (auto pair: zip(range(0,5), range(7,12))) {
		testcase.CHECK_OUTPUT(pair,Check13[temp]);
		temp++;
        }

        temp=0;
		string Check14[]={"-1,a","0,b","1,c","2,d"};
        for (auto pair: zip(range(-1,3), range('a','e'))) {
		testcase.CHECK_OUTPUT(pair,Check14[temp]);
		temp++;
        }

        temp=0;
		string Check15[]={"A,a","B,b","C,c","D,d"};
        for (auto pair: zip(range('A','E'), range('a','e'))) {
		testcase.CHECK_OUTPUT(pair,Check15[temp]);
		temp++;
}

	// PowerSet:
	    testcase.setname(" Test PowerSet");
	    temp=0;
		string Check16[]={"{}","{5}","{6}","{5,6}","{7}","{5,7}","{6,7}","{5,6,7}"};
        for (auto pair: powerset(range(5,8))){
		testcase.CHECK_OUTPUT(pair,Check16[temp]);
		temp++;
}

	    temp=0;
		string Check17[]={"{}","{a}","{b}","{a,b}","{1}","{a,1}","{b,1}","{a,b,1}","{2}","{a,2}","{b,2}","{a,b,2}","{1,2}","{a,1,2}","{b,1,2}","{a,b,1,2}"};
        for (auto subset: powerset(chain(range('a','c'),range('1','3')))) {
		testcase.CHECK_OUTPUT(subset,Check17[temp]);
		temp++;
}

	temp=0;
	string Check18[]={"{}","{c}","{p}","{c,p}","{p}","{c,p}","{p,p}","{c,p,p}"};
    for (auto subset: powerset(string("cpp"))) {
	  testcase.CHECK_OUTPUT(subset,Check18[temp]);
 	   temp++;
}

////////////////////////////////// end_MyTest ////////////////////////////////////////

    grade = testcase.grade();
	}
	else
	{
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}

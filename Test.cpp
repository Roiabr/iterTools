
#include <iostream>
using namespace std;

#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace itertools;



int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {
		
		string rangeInt1 = "",rangeInt2 = "",rangeInt3 = "",rangeInt4= "",rangeInt5 = "",rangeInt6 = "",rangeDouble1 = "",rangeDouble2 = "",rangeDouble3 = "",rangeChar = "",chainInt1 = "",chainInt2 = "",chainInt3 = "",chainInt4= "",chainInt5 = "",chainInt6 = "",chainDouble1 = "",chainDouble2 = "",chainDouble3 = "",chainChar = "",zipInt1 = "",zipDouble1 = "",zipDouble2 = "",zipDouble3 = "",zipChar = "" ,zipDOuble5 ="";
		ostringstream streamProduct1,streamProduct2,streamProduct3,streamProduct4,streamPowerSet1,streamPowerSet2;



		/////////////////RANGES/////////////////////////
		for (int i: range(1,10)){rangeInt1 = rangeInt1 + to_string(i);}
		for (int i: range(10,20)){rangeInt2 = rangeInt2 + to_string(i);}
		for (int i: range(20,30)){rangeInt3 = rangeInt3 + to_string(i);}
		for (int i: range(30,40)){rangeInt4 = rangeInt4 + to_string(i);}
		for (int i: range(40,50)){rangeInt5 = rangeInt5 + to_string(i);}
		for (int i: range(50,60)){rangeInt6 = rangeInt6 + to_string(i);}
		for (double i: range(5.1,9.1)){rangeDouble1 = rangeDouble1 + to_string(i);}
		for (double i: range(10.1,20.1)){rangeDouble2 = rangeDouble2 + to_string(i);}
		for (double i: range(20.1,25.1)){rangeDouble3 = rangeDouble3 + to_string(i);}
		for (char i: range('d','k')){rangeChar = rangeChar + i;}
		
		testcase.setname("Ranges")
		.CHECK_OUTPUT(rangeInt1, "123456789")
		.CHECK_OUTPUT(rangeInt2, "10111213141516171819")
		.CHECK_OUTPUT(rangeInt3, "20212223242526272829")
		.CHECK_OUTPUT(rangeInt4, "30313233343536373839")
		.CHECK_OUTPUT(rangeInt5, "40414243444546474849")
		.CHECK_OUTPUT(rangeInt6, "50515253545556575859")
		.CHECK_OUTPUT(rangeDouble1, "5.1000006.1000007.1000008.100000")
		.CHECK_OUTPUT(rangeDouble2, "10.10000011.10000012.10000013.10000014.10000015.10000016.10000017.10000018.10000019.100000")
		.CHECK_OUTPUT(rangeDouble3, "20.10000021.10000022.10000023.10000024.100000")
		.CHECK_OUTPUT(rangeChar, "defghij");


///////////////////CHAINS////////////////////////
		for (int i: chain(range(1,10),range(10,20))){chainInt1 = chainInt1 + to_string(i);}
		for (int i: chain(range(30,40), range(40,50))){chainInt2 = chainInt2 + to_string(i);}
		for (int i: chain(range(50,60), range(60,70))){chainInt3 = chainInt3 + to_string(i);}
		for (double i: chain(range(10.1,20.1),range(20.1,25.1))){chainDouble1 = chainDouble1 + to_string(i);}
		for (char i: chain(range('a','d'),range('d','k'))){chainChar = chainChar + i;}
		
		
		testcase.setname("Chains")
		.CHECK_OUTPUT(chainInt1,rangeInt1+rangeInt2 )
		.CHECK_OUTPUT(chainInt2,rangeInt4 + rangeInt5)
		.CHECK_OUTPUT(chainInt3,rangeInt6 + "60616263646566676869")
		.CHECK_OUTPUT(chainDouble1,rangeDouble2+rangeDouble3)
		.CHECK_OUTPUT(chainChar, "abc" + rangeChar);

		//////////////////ZIP////////////////////////
	for (auto pair: zip(range(1,6), string("hello"))){zipInt1 = zipInt1 + to_string(pair.first) + pair.second;}
	for (auto pair: zip(range('a','d'), string("zip"))){zipChar = zipChar + pair.first + pair.second;}
	for (auto pair: zip(range(2.5,3.5), range('a','b'))){zipDouble1 = zipDouble1 + to_string(pair.first) + pair.second;}
	for (auto pair: zip(range(33.2,42.2), range(20,30))){zipDouble2 = zipDouble2 + to_string(pair.first) + to_string(pair.second);}
	for (auto pair: zip(string("cpp"), range(50,60))){zipDouble3 = zipDouble3 + pair.first + to_string(pair.second);}
	for (auto pair: zip(range(-9,-4),range(5,10))){zipDOuble5 = zipDOuble5 + to_string(pair.first) + to_string(pair.second);}
	

		testcase.setname("zip")
		.CHECK_OUTPUT(zipInt1,"1h2e3l4l5o")
		.CHECK_OUTPUT(zipChar,"azbicp")
		.CHECK_OUTPUT(zipDouble1,"2.500000a")
		.CHECK_OUTPUT(zipDouble2,"33.2000002034.2000002135.2000002236.2000002337.2000002438.2000002539.2000002640.2000002741.20000028")
		.CHECK_OUTPUT(zipDouble3,"c50p51p52")
		.CHECK_OUTPUT(zipDOuble5,"-95-86-77-68-59");
		

//////////////////////PRODUCTS/////////////////////////////
		testcase.setname("product");
		for (auto pair: product(range(1,4),string("hello")))
			streamProduct1 << pair << " ";
		testcase.CHECK_OUTPUT(streamProduct1.str(),"1,h 1,e 1,l 1,l 1,o 2,h 2,e 2,l 2,l 2,o 3,h 3,e 3,l 3,l 3,o ");
		for (auto pair: product(range('a','h'),chain(range(1.1,4.1),range(20,30))))
			streamProduct2 << pair << " ";
		testcase.CHECK_OUTPUT(streamProduct2.str(),"a,1.1 a,2.1 a,3.1 a,20 a,21 a,22 a,23 a,24 a,25 a,26 a,27 a,28 a,29 b,1.1 b,2.1 b,3.1 b,20 b,21 b,22 b,23 b,24 b,25 b,26 b,27 b,28 b,29 c,1.1 c,2.1 c,3.1 c,20 c,21 c,22 c,23 c,24 c,25 c,26 c,27 c,28 c,29 d,1.1 d,2.1 d,3.1 d,20 d,21 d,22 d,23 d,24 d,25 d,26 d,27 d,28 d,29 e,1.1 e,2.1 e,3.1 e,20 e,21 e,22 e,23 e,24 e,25 e,26 e,27 e,28 e,29 f,1.1 f,2.1 f,3.1 f,20 f,21 f,22 f,23 f,24 f,25 f,26 f,27 f,28 f,29 g,1.1 g,2.1 g,3.1 g,20 g,21 g,22 g,23 g,24 g,25 g,26 g,27 g,28 g,29 ");
		for (auto i: product(product(string("product"),range(1,3)),product(string("test"),range(4,5))))
			streamProduct3 << i << " ";
		testcase.CHECK_OUTPUT(streamProduct3.str(),"p,1,t,4 p,1,e,4 p,1,s,4 p,1,t,4 p,2,t,4 p,2,e,4 p,2,s,4 p,2,t,4 r,1,t,4 r,1,e,4 r,1,s,4 r,1,t,4 r,2,t,4 r,2,e,4 r,2,s,4 r,2,t,4 o,1,t,4 o,1,e,4 o,1,s,4 o,1,t,4 o,2,t,4 o,2,e,4 o,2,s,4 o,2,t,4 d,1,t,4 d,1,e,4 d,1,s,4 d,1,t,4 d,2,t,4 d,2,e,4 d,2,s,4 d,2,t,4 u,1,t,4 u,1,e,4 u,1,s,4 u,1,t,4 u,2,t,4 u,2,e,4 u,2,s,4 u,2,t,4 c,1,t,4 c,1,e,4 c,1,s,4 c,1,t,4 c,2,t,4 c,2,e,4 c,2,s,4 c,2,t,4 t,1,t,4 t,1,e,4 t,1,s,4 t,1,t,4 t,2,t,4 t,2,e,4 t,2,s,4 t,2,t,4 ");
		
		
		////////////////////POWERSETS//////////////////
		testcase.setname("powerset");
		for (auto i: powerset(string("123")))
			streamPowerSet1 << i << " "; 
		testcase.CHECK_OUTPUT(streamPowerSet1.str(),"{},{a},{b},{a,b},{c},{a,c},{b,c},{a,b,c}");
		for (auto i: powerset(chain(range('a','d'),range('x','z'))))
			streamPowerSet2 << i << " "; 
		testcase.CHECK_OUTPUT(streamPowerSet2.str(),"{},{a},{b},{ab},{c},{ac},{bc},{abc},{},{x},{y},{xy}");

				
		
		



	

		
		

		

		
		


		
		



	
    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}
# verbose
simple C++ -v --verbose switch.
___

use Verbose namespace :
```C++
	using namespace Verbose;
```
___
-=-=-=-=-

find -v or --verbose switch :
```C++
	int main(int argc ,char** argv){
		confirmVerbose(argc ,argv);
```
that will set `Verbose::verbose` to `true` and that's how Verbose knows if program is verbose or not
___
-=-=-=-=-

cout something if `verbose == true` :
```C++
	verb << "this line will be printed if there is -v\n";
```
you can't use `endl` for new line. (and you better not use it if you only want new line with `cout`)
use `'\n'` or `vendl` for new line.
___
-=-=-=-=-

using `cout` and `verb` together :
```C++
	cout << "a" << verb << "b";
```
`a` will be printed but for `b` that happens only if `verbose == true`. 
this line returns `Verb`

```C++
	verb << "a" << cout << "b";
```
`b` will be printed but for `a` that happens only if `verbose == true`. 
this line returns `ostream`
___
-=-=-=-=-

`verb` to a file :
```C++
	ofstream file;
	file.open("./log");
	Verb verbToFile(file);
	verbToFile << "from Verb\n";
	file.close();
```
don't forget `#include<fstream>` !
___
-=-=-=-=-

EXAMPLE
```C++
#include<iostream>
#include<fstream>
#include"verbose"
using namespace std;
using namespace Verbose;
int main(){
    verbose = false;
    cout << "a" << verb << "b" << cout << "c" << verb << "d" << cout << '\n';
    verb << "a" << cout << "b" << verb << "c" << cout << "d" << verb << '\n';
    verbose = true;
    cout << '\n';
    cout << "a" << verb << "b" << cout << "c" << verb << "d" << cout << '\n';
    
    ofstream file;
    file.open("./log");
    Verb verbToFile(file);
    verbToFile << "from Verb\n";
    file.close();
}
```
___
-=-=-=-=-
force1267@gmail.com
happy verbing !

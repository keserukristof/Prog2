#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>
#include <iostream>
#include <string>
namespace fs = boost::filesystem;
int main() {
    fs::path dir("./src/");
    bool IsSrcDirThere =false;
    while(!IsSrcDirThere){
			if(fs::exists(dir)){
				IsSrcDirThere =true;
			}
			else{
				std::cout << "Nem talalhato a(z)"<< dir 
						<<"mappa! kerem adja meg az eleresi helyet" << std::endl;
			std::string NewDir;
			std::cin >> NewDir;
			if(NewDir.at(NewDir.length()-1)!='/')
				NewDir.append("/");
			dir= NewDir;
			}
    }
	fs::recursive_directory_iterator it(dir), end;
	std::vector<std::string> JdkClasses;
    for (auto& entry : boost::make_iterator_range(it, end)){
		if (is_regular(entry)){
			std::string tmp=entry.path().native();
			std::string tmp2=tmp.substr(tmp.length()-5);
			if(tmp2== ".java")
				JdkClasses.push_back(tmp);
			}
	}
	for(auto& JDKClass : JdkClasses)
		std::cout << JDKClass .substr(dir.string().length())<< std::endl;
		
exit(0);
}


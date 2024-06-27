#include<vector>
#include<cassert>
#include<string>

namespace shizu{
class rotate_vec{
/* ccw 90degree */
public:
	template<class T>
	std::vector<std::vector<T>> vvRotate(const std::vector<std::vector<T>> &vec){
		assert(vec.size()>0);
		assert(vec.size() == vec[0].size());
		int n = (int)vec.size();
		int m = (int)vec[0].size();
		std::vector<std::vector<T>> ret(m,std::vector<T>(n));
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				ret[m-j-1][i] = vec[i][j];
			}
		}
		return ret;
	}

	std::vector<std::string> vsRotate(const std::vector<std::string> &vec){
		assert(vec.size()>0);
		assert(vec[0].size()>0);
		int n = (int)vec.size();
		int m = (int)vec[0].size();
		std::vector<std::string> ret(m,std::string(n,' '));
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				ret[m-j-1][i] = vec[i][j];
			}
		}

		return ret;
	}

	template<class T>
	std::vector<std::vector<T>> vvTrans(const std::vector<std::vector<T>> &vec){
		assert(vec.size()>0);
		assert(vec[0].size()>0);
		int n = (int)vec.size();
		int m = (int)vec[0].size();
		std::vector<std::vector<T>> ret(n,std::vector<T>(m));
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				ret[j][i] = vec[i][j];
			}
		}
		return ret;
	}

	std::vector<std::string> vsTrans(const std::vector<std::string> &vec){
		assert(vec.size()>0);
		assert(vec[0].size()>0);
		int n = (int)vec.size();
		int m = (int)vec[0].size();
		std::vector<std::string> ret(n,std::string(m,' '));
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				ret[j][i] = vec[i][j];
			}
		}
		return ret;
	}
};
}// namespace shizu
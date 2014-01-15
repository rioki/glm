
#ifndef _GLM_UTILS_H_
#define _GLM_UTILS_H_

namespace glm
{
    template <typename T>
	T deg2rad(T d)
	{		
		T pi = static_cast<T>(3.1415926535897932384626433832795);
		return d * (pi / static_cast<T>(180));
	}
}

#endif

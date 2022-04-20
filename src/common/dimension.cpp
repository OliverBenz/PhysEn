#include "dimension.hpp"

namespace phys {

std::ostream& operator << (std::ostream& os, const dimension& size){
	return os << "dimension(" << size.rows << ", " << size.columns << ")\n";
}

}
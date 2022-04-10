#include "size.hpp"

namespace PhysEn{

std::ostream& operator << (std::ostream& os, const Size& size){
	return os << "Size(" << size.rows << ", " << size.columns << ")\n";
}

}

#include "TexCordArray.h"

TexCordArray::TexCordArray()
{
}

TexCordArray::TexCordArray(std::vector<Quad>& texCords)
{
	this->set(texCords);
}

TexCordArray::~TexCordArray()
{
}

void TexCordArray::set(std::vector<Quad>& texCords)
{
	if (texCords.size() >= 1) {
		Quad* sourceQuadArray = texCords.data();
		quadArray.set(new Quad[texCords.size()], texCords.size());

		std::memcpy(quadArray.getPtr(), sourceQuadArray, sizeof(Quad) * texCords.size());
	}
}

#include "BitArray.h"
#include<assert.h>

BitArray::BitArray()
{
}

BitArray::BitArray(size_t i_numBits, HeapAllocator i_pManager, bool i_startClear) {
	Create(i_numBits, i_pManager, i_startClear);
}

BitArray * BitArray::Create(size_t i_numBits, HeapAllocator  i_pManager, bool i_startClear) {
	m_pBits = new uint8_t[i_numBits / bitsPerBytes];
	assert(m_pBits);
	m_numBits = i_numBits;
	memset(m_pBits, i_startClear ? 0 : 1, i_numBits / bitsPerBytes);
	return (BitArray *)m_pBits;
}

void BitArray::ClearAll(void) {
	memset(m_pBits, 0, m_numBits / bitsPerBytes);
}

void BitArray::SetAll(bool i_SetAll) {
	memset(m_pBits, i_SetAll ? 0 : 1, m_numBits / bitsPerBytes);
}

bool BitArray::AreAllClear(void) const
{
	int index = 0;
	size_t m_numBytes = m_numBits / bitsPerBytes;

	while ((m_pBits[index] == 0x00) && (index < m_numBytes)) {
		index++;
	}
	if (index == m_numBytes) {
		return true;
	}
	return false;
}

bool BitArray::AreAllSet(void) const {
	return !AreAllClear();
}

bool BitArray::IsBitSet(size_t bitNumber) const {
	size_t byteNumber = bitNumber / bitsPerBytes;
	if (m_pBits[byteNumber] & 1 << (bitNumber - byteNumber * bitsPerBytes)) {
		return true;
	}
	return false;
}

bool BitArray::IsBitClear(size_t bitNumber) const {
	return !IsBitSet(bitNumber);
}

void BitArray::SetBit(size_t bitNumber) {
	size_t byteNumber = bitNumber / bitsPerBytes;
	m_pBits[byteNumber] |= 1 << (bitNumber - byteNumber * bitsPerBytes);
}

void BitArray::ClearBit(size_t bitNumber) {
	size_t byteNumber = bitNumber / bitsPerBytes;
	m_pBits[byteNumber] |= 0 << (bitNumber - byteNumber * bitsPerBytes);
}

size_t BitArray::GetFirstSetBit() const {
	size_t index = 0;
	size_t m_numBytes = m_numBits / bitsPerBytes;
	// quick skip bytes where no bits are set   
	while ((m_pBits[index] == 0x00) && (index < m_numBytes)) {
		index++;
	}

	if (index == m_numBytes) {
		return false;
	}
	else {
		uint8_t byte = m_pBits[index];
		size_t 	bit;

		for (bit = 0; bit < 8; bit++)
			if (byte & (1 << bit))
				break;

		// now we've found the byte and the bit
		size_t bitset = index * 8 + bit;

		return bitset;
	}




}

size_t BitArray::GetFirstClearBit() const
{
	size_t index = 0;
	size_t m_numBytes = m_numBits / bitsPerBytes;
	// quick skip bytes where no bits are set   
	while ((m_pBits[index] == 0xff) && (index < m_numBytes)) {
		index++;
	}

	if (index == m_numBytes) {
		return 0;
	}
	else {
		uint8_t byte = m_pBits[index];
		size_t 	bit;

		for (bit = 0; bit < 8; bit++)
			if (!(byte & (1 << bit)))
				break;

		// now we've found the byte and the bit
		size_t bitset = index * 8 + bit;

		return bitset;
	}
}
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <openabe/openabe.h>
#include <openabe/zsymcrypto.h>
#include <gtest/gtest.h>

using namespace oabe;
using namespace oabe::crypto;
using namespace std;

TEST(OABE_CHECK, Initialization) {
	InitializeOpenABE();
	ShutdownOpenABE();
}

TEST(OABE_CHECK, CP_ABE_CONTEXT) {
	InitializeOpenABE();
	OpenABECryptoContext cpabe("CP-ABE");
	string ct, pt1 = "hello world!", pt2;
	cpabe.generateParams();
	cpabe.keygen("|attr1|attr2", "key0");
	cpabe.encrypt("attr1 and attr2", pt1, ct);
	bool result = cpabe.decrypt("key0", ct, pt2);
	ASSERT_TRUE(result);
	ShutdownOpenABE();
}

TEST(OABE_CHECK, KP_ABE_CONTEXT) {
	InitializeOpenABE();
	OpenABECryptoContext kpabe("KP-ABE");
	string ct, pt1 = "hello world!", pt2;
	kpabe.generateParams();
	kpabe.keygen("attr1 and attr2", "key0");
	kpabe.encrypt("|attr1|attr2", pt1, ct);
	bool result = kpabe.decrypt("key0", ct, pt2);
	ASSERT_TRUE(result);
	ShutdownOpenABE();
}
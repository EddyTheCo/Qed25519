#include"crypto/qed25519.hpp"
#include<iostream>
#undef NDEBUG
#include <assert.h>
#include<QDebug>
/*
 *https://github.com/iotaledger/tips/blob/main/tips/TIP-0014/tip-0014.md
 * 
 */
using namespace qcrypto::qed25519;


int main(int argc, char** argv)
{
    auto message=QByteArray::fromHex("8c93255d71dcab10e8f379c26200f3c7bd5f09d9bc3068d3ef4edeb4853022b6");
    auto pub_key=QByteArray::fromHex("c7176a703d4dd84fba3c0b760d10670f2a2053fa2c39ccc64ec7fd7792ac03fa");
    auto signature=QByteArray::fromHex("c7176a703d4dd84fba3c0b760d10670f2a2053fa2c39ccc64ec7fd7792ac037a0000000000000000000000000000000000000000000000000000000000000000");

    assert(verify(signature,message,pub_key)==true&& "Test-vector 1");


    message=QByteArray::fromHex("9bd9f44f4dcc75bd531b56b2cd280b0bb38fc1cd6d1230e14861d861de092e79");
    pub_key=QByteArray::fromHex("c7176a703d4dd84fba3c0b760d10670f2a2053fa2c39ccc64ec7fd7792ac03fa");
    signature=QByteArray::fromHex("f7badec5b8abeaf699583992219b7b223f1df3fbbea919844e3f7c554a43dd43a5bb704786be79fc476f91d3f3f89b03984d8068dcf1bb7dfc6637b45450ac04");

    assert(verify(signature,message,pub_key)==true&& "Test-vector 2");


    message=QByteArray::fromHex("aebf3f2601a0c8c5d39cc7d8911642f740b78168218da8471772b35f9d35b9ab");
    pub_key=QByteArray::fromHex("f7badec5b8abeaf699583992219b7b223f1df3fbbea919844e3f7c554a43dd43");
    signature=QByteArray::fromHex("c7176a703d4dd84fba3c0b760d10670f2a2053fa2c39ccc64ec7fd7792ac03fa8c4bd45aecaca5b24fb97bc10ac27ac8751a7dfe1baff8b953ec9f5833ca260e");

    assert(verify(signature,message,pub_key)==true&& "Test-vector 3");

    message=QByteArray::fromHex("9bd9f44f4dcc75bd531b56b2cd280b0bb38fc1cd6d1230e14861d861de092e79");
    pub_key=QByteArray::fromHex("cdb267ce40c5cd45306fa5d2f29731459387dbf9eb933b7bd5aed9a765b88d4d");
    signature=QByteArray::fromHex("9046a64750444938de19f227bb80485e92b83fdb4b6506c160484c016cc1852f87909e14428a7a1d62e9f22f3d3ad7802db02eb2e688b6c52fcd6648a98bd009");

    assert(verify(signature,message,pub_key)==true&& "Test-vector 4");


    message=QByteArray::fromHex("e47d62c63f830dc7a6851a0b1f33ae4bb2f507fb6cffec4011eaccd55b53f56c");
    pub_key=QByteArray::fromHex("cdb267ce40c5cd45306fa5d2f29731459387dbf9eb933b7bd5aed9a765b88d4d");
    signature=QByteArray::fromHex("160a1cb0dc9c0258cd0a7d23e94d8fa878bcb1925f2c64246b2dee1796bed5125ec6bc982a269b723e0668e540911a9a6a58921d6925e434ab10aa7940551a09");

    //assert(verify(signature,message,pub_key)==true&& "Test-vector 5");

    message=QByteArray::fromHex("e47d62c63f830dc7a6851a0b1f33ae4bb2f507fb6cffec4011eaccd55b53f56c");
    pub_key=QByteArray::fromHex("cdb267ce40c5cd45306fa5d2f29731459387dbf9eb933b7bd5aed9a765b88d4d");
    signature=QByteArray::fromHex("21122a84e0b5fca4052f5b1235c80a537878b38f3142356b2c2384ebad4668b7e40bc836dac0f71076f9abe3a53f9c03c1ceeeddb658d0030494ace586687405");

    //assert(verify(signature,message,pub_key)==true&& "Test-vector 6");


    message=QByteArray::fromHex("85e241a07d148b41e47d62c63f830dc7a6851a0b1f33ae4bb2f507fb6cffec40");
    pub_key=QByteArray::fromHex("442aad9f089ad9e14647b1ef9099a1ff4798d78589e66f28eca69c11f582a623");
    signature=QByteArray::fromHex("e96f66be976d82e60150baecff9906684aebb1ef181f67a7189ac78ea23b6c0e547f7690a0e2ddcd04d87dbc3490dc19b3b3052f7ff0538cb68afb369ba3a514");

    //assert(verify(signature,message,pub_key)==false&& "Test-vector 7");


    message=QByteArray::fromHex("85e241a07d148b41e47d62c63f830dc7a6851a0b1f33ae4bb2f507fb6cffec40");
    pub_key=QByteArray::fromHex("442aad9f089ad9e14647b1ef9099a1ff4798d78589e66f28eca69c11f582a623");
    signature=QByteArray::fromHex("8ce5b96c8f26d0ab6c47958c9e68b937104cd36e13c33566acd2fe8d38aa19427e71f98a473474f2f13f06f97c20d58cc3f54b8bd0d272f42b695dd7e89a8c22");

    assert(verify(signature,message,pub_key)==false&& "Test-vector 8");

    message=QByteArray::fromHex("9bedc267423725d473888631ebf45988bad3db83851ee85c85e241a07d148b41");
    pub_key=QByteArray::fromHex("f7badec5b8abeaf699583992219b7b223f1df3fbbea919844e3f7c554a43dd43");
    signature=QByteArray::fromHex("ecffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff03be9678ac102edcd92b0210bb34d7428d12ffc5df5f37e359941266a4e35f0f");

    assert(verify(signature,message,pub_key)==false&& "Test-vector 9");


    message=QByteArray::fromHex("9bedc267423725d473888631ebf45988bad3db83851ee85c85e241a07d148b41");
    pub_key=QByteArray::fromHex("f7badec5b8abeaf699583992219b7b223f1df3fbbea919844e3f7c554a43dd43");
    signature=QByteArray::fromHex("ecffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffca8c5b64cd208982aa38d4936621a4775aa233aa0505711d8fdcfdaa943d4908");

    //assert(verify(signature,message,pub_key)==true&& "Test-vector 10");


    message=QByteArray::fromHex("e96b7021eb39c1a163b6da4e3093dcd3f21387da4cc4572be588fafae23c155b");
    pub_key=QByteArray::fromHex("ecffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
    signature=QByteArray::fromHex("a9d55260f765261eb9b84e106f665e00b867287a761990d7135963ee0a7d59dca5bb704786be79fc476f91d3f3f89b03984d8068dcf1bb7dfc6637b45450ac04");

    assert(verify(signature,message,pub_key)==false&& "Test-vector 11");

    message=QByteArray::fromHex("39a591f5321bbe07fd5a23dc2f39d025d74526615746727ceefd6e82ae65c06f");
    pub_key=QByteArray::fromHex("ecffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
    signature=QByteArray::fromHex("a9d55260f765261eb9b84e106f665e00b867287a761990d7135963ee0a7d59dca5bb704786be79fc476f91d3f3f89b03984d8068dcf1bb7dfc6637b45450ac04");

    assert(verify(signature,message,pub_key)==true&& "Test-vector 12");

	return 0;
}

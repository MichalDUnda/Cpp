#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "lambda.hpp"

int main(int argc, char* argv[])

{
    IntType i;
    exampleFuncForIsSupported<IntType>(i);

    if(exampleFuncForIsSupportedWithReturnType<IntType>(i))
    {
        std::cout << "TRUE" << std::endl;
    }

    StringType s;
    // not compilable because exampleFuncForIsSupported not support StringType
    // exampleFuncForIsSupported<StringType>(s);

    HasTypeFunc hasTypeObj;
    HasNotTypeFunc hasNotTypeObj;

    exampleFunctionWitchHasType<HasTypeFunc>(hasTypeObj);
    exampleFunctionWitchHasType<IntType>(i);

    exampleFunctionWitchHasMemberVariable<HasTypeFunc>(hasTypeObj);
    //exampleFunctionWitchHasType<HasNotTypeFunc>(hasNotTypeObj);

    HasStringVariable strVAr;
    exampleFunctionWitchHasMemberVariable<HasStringVariable>(strVAr);
    return 0;
}
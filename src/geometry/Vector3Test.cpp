#include <Vector3Test.hpp>

#include <Vector3.hpp>

Vector3Test Vector3Test::instance;
Vector3Test* Vector3Test::getInstance() {
    return &instance;
}

void Vector3Test::run() {
    testAttributes();
    testAssignment();
    testOperatorAssignment();
    testOperatorConstructor();
    testLength();
    testMakeUnit();
    testOperatorRHS();
    testDotAndCross();
}

void Vector3Test::testAttributes() {
    Vector3 v1;
    TestSuite::floatEqual(v1.x(), 0);
    TestSuite::floatEqual(v1.y(), 0);
    TestSuite::floatEqual(v1.z(), 0);

    Vector3 v2(1.2, 3.4, 5.6);
    TestSuite::floatEqual(v2.x(), 1.2);
    TestSuite::floatEqual(v2.y(), 3.4);
    TestSuite::floatEqual(v2.z(), 5.6);

    Vector3 v3(v2);
    TestSuite::floatEqual(v3.x(), 1.2);
    TestSuite::floatEqual(v3.y(), 3.4);
    TestSuite::floatEqual(v3.z(), 5.6);
}

void Vector3Test::testAssignment() {
    Vector3 v1(1.2, 3.4, 5.6);
    Vector3 v2;
    v2 = v1;

    TestSuite::floatEqual(v1.x(), 1.2);
    TestSuite::floatEqual(v1.y(), 3.4);
    TestSuite::floatEqual(v1.z(), 5.6);

    TestSuite::floatEqual(v1.x(), v2.x());
    TestSuite::floatEqual(v1.y(), v2.y());
    TestSuite::floatEqual(v1.z(), v2.z());

}

void Vector3Test::testOperatorAssignment() {
    Vector3 v1(1, 2, 3);
    Vector3 v2(4, 5, 6);
    v1 += v2;
    TestSuite::floatEqual(v1.x(), 5);
    TestSuite::floatEqual(v1.y(), 7);
    TestSuite::floatEqual(v1.z(), 9);
    TestSuite::floatEqual(v2.x(), 4);
    TestSuite::floatEqual(v2.y(), 5);
    TestSuite::floatEqual(v2.z(), 6);

    Vector3 v3(4, 5, 6);
    Vector3 v4(1, 2, 3);
    v3 -= v4;
    TestSuite::floatEqual(v3.x(), 3);
    TestSuite::floatEqual(v3.y(), 3);
    TestSuite::floatEqual(v3.z(), 3);
    TestSuite::floatEqual(v4.x(), 1);
    TestSuite::floatEqual(v4.y(), 2);
    TestSuite::floatEqual(v4.z(), 3);

    Vector3 v5(1, 2, 3);
    v5 *= 5;
    TestSuite::floatEqual(v5.x(), 5);
    TestSuite::floatEqual(v5.y(), 10);
    TestSuite::floatEqual(v5.z(), 15);

    Vector3 v6(1, 2, 3);
    v6 /= 2;
    TestSuite::floatEqual(v6.x(), 0.5);
    TestSuite::floatEqual(v6.y(), 1);
    TestSuite::floatEqual(v6.z(), 1.5);

    Vector3 v7(1, 2, 3);
    Vector3 v8(4, 5, 6);
    v7 *= v8;
    TestSuite::floatEqual(v7.x(), 4);
    TestSuite::floatEqual(v7.y(), 10);
    TestSuite::floatEqual(v7.z(), 18);
    TestSuite::floatEqual(v8.x(), 4);
    TestSuite::floatEqual(v8.y(), 5);
    TestSuite::floatEqual(v8.z(), 6);
}

void Vector3Test::testOperatorConstructor() {
    Vector3 v1(1, 2, 3);
    Vector3 v2(4, 5, 6);
    Vector3 v3 = v1 + v2;
    TestSuite::floatEqual(v1.x(), 1);
    TestSuite::floatEqual(v1.y(), 2);
    TestSuite::floatEqual(v1.z(), 3);
    TestSuite::floatEqual(v2.x(), 4);
    TestSuite::floatEqual(v2.y(), 5);
    TestSuite::floatEqual(v2.z(), 6);
    TestSuite::floatEqual(v3.x(), 5);
    TestSuite::floatEqual(v3.y(), 7);
    TestSuite::floatEqual(v3.z(), 9);

    Vector3 v4(4, 5, 6);
    Vector3 v5(1, 2, 3);
    Vector3 v6 = v4 - v5;
    TestSuite::floatEqual(v4.x(), 4);
    TestSuite::floatEqual(v4.y(), 5);
    TestSuite::floatEqual(v4.z(), 6);
    TestSuite::floatEqual(v5.x(), 1);
    TestSuite::floatEqual(v5.y(), 2);
    TestSuite::floatEqual(v5.z(), 3);
    TestSuite::floatEqual(v6.x(), 3);
    TestSuite::floatEqual(v6.y(), 3);
    TestSuite::floatEqual(v6.z(), 3);

    Vector3 v7(1, 2, 3);
    Vector3 v8 = v7 * 5;
    TestSuite::floatEqual(v7.x(), 1);
    TestSuite::floatEqual(v7.y(), 2);
    TestSuite::floatEqual(v7.z(), 3);
    TestSuite::floatEqual(v8.x(), 5);
    TestSuite::floatEqual(v8.y(), 10);
    TestSuite::floatEqual(v8.z(), 15);

    Vector3 v9(1, 2, 3);
    Vector3 v10 = v9 / 2;
    TestSuite::floatEqual(v9.x(), 1);
    TestSuite::floatEqual(v9.y(), 2);
    TestSuite::floatEqual(v9.z(), 3);
    TestSuite::floatEqual(v10.x(), 0.5);
    TestSuite::floatEqual(v10.y(), 1);
    TestSuite::floatEqual(v10.z(), 1.5);

    Vector3 v11(1, 2, 3);
    Vector3 v12(4, 5, 6);
    Vector3 v13 = v11 * v12;
    TestSuite::floatEqual(v11.x(), 1);
    TestSuite::floatEqual(v11.y(), 2);
    TestSuite::floatEqual(v11.z(), 3);
    TestSuite::floatEqual(v12.x(), 4);
    TestSuite::floatEqual(v12.y(), 5);
    TestSuite::floatEqual(v12.z(), 6);
    TestSuite::floatEqual(v13.x(), 4);
    TestSuite::floatEqual(v13.y(), 10);
    TestSuite::floatEqual(v13.z(), 18);
}

void Vector3Test::testLength() {
    Vector3 v1(3, 4, 5);
    // sqrt(9, 16, 25) = sqrt(50) ~ 7.071
    TestSuite::floatEqual(v1.x(), 3);
    TestSuite::floatEqual(v1.y(), 4);
    TestSuite::floatEqual(v1.z(), 5);
    TestSuite::floatEqual(v1.length(), 7.071);
}

void Vector3Test::testMakeUnit() {
    Vector3 v1(3, 4, 5);
    Vector3 v2 = v1.make_unit();
    TestSuite::floatEqual(v1.x(), 3);
    TestSuite::floatEqual(v1.y(), 4);
    TestSuite::floatEqual(v1.z(), 5);
    TestSuite::floatEqual(v2.length(), 1);

    Vector3 v3 = v2 * v1.length();
    TestSuite::floatEqual(v1.x(), v3.x());
    TestSuite::floatEqual(v1.y(), v3.y());
    TestSuite::floatEqual(v1.z(), v3.z());
}

void Vector3Test::testOperatorRHS() {
    Vector3 v1(1, 2, 3);
    Vector3 v2 = 5 * v1;
    TestSuite::floatEqual(v1.x(), 1);
    TestSuite::floatEqual(v1.y(), 2);
    TestSuite::floatEqual(v1.z(), 3);
    TestSuite::floatEqual(v2.x(), 5);
    TestSuite::floatEqual(v2.y(), 10);
    TestSuite::floatEqual(v2.z(), 15);
}

void Vector3Test::testDotAndCross() {
    Vector3 v1(1, 10, 100);
    Vector3 v2(2, 4, 6);
    // 2 + 40 + 600 = 642
    TestSuite::floatEqual(v1.x(), 1);
    TestSuite::floatEqual(v1.y(), 10);
    TestSuite::floatEqual(v1.z(), 100);
    TestSuite::floatEqual(v2.x(), 2);
    TestSuite::floatEqual(v2.y(), 4);
    TestSuite::floatEqual(v2.z(), 6);
    TestSuite::floatEqual(dot(v1, v2), 642);

    Vector3 v3(1, 2, 1);
    Vector3 v4(6, 5, 3);
    // 2*3 - 5*1 = 1
    // -((1*3) - (1*6)) = 3
    // 1*5 - 2*6 = -7
    Vector3 v5 = cross(v3, v4);
    TestSuite::floatEqual(v3.x(), 1);
    TestSuite::floatEqual(v3.y(), 2);
    TestSuite::floatEqual(v3.z(), 1);
    TestSuite::floatEqual(v4.x(), 6);
    TestSuite::floatEqual(v4.y(), 5);
    TestSuite::floatEqual(v4.z(), 3);
    TestSuite::floatEqual(v5.x(), 1);
    TestSuite::floatEqual(v5.y(), 3);
    TestSuite::floatEqual(v5.z(), -7);
}
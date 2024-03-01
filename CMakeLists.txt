cmake_minimum_required(VERSION 3.27)
project(data_struct_c)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(data_struct_c
        "02 LinerList/utils/LinkedListUtil.cpp"
        "02 LinerList/01SeqList01_Static.cpp"
        "02 LinerList/02SeqList02_Dynamic.cpp"
        "02 LinerList/03SeqList_Node.cpp"
        "02 LinerList/04SeqList_Build.cpp"
        ins.h
        "02 LinerList/05SeqList_DLinkedList.cpp")

add_executable(04SeqList_Build "02 LinerList/04SeqList_Build.cpp" "02 LinerList/utils/LinkedListUtil.cpp"
        03Stack/01Stack_static.cpp)
add_executable(05SeqList_DLinkedList "02 LinerList/05SeqList_DLinkedList.cpp")
add_executable(01Stack_static 03Stack/01Stack_static.cpp
        03Stack/02Stack_Share.cpp
        03Stack/03Stack_linked.cpp
        04queue/queue.h
        04queue/01_CQueueTest.cpp
        03Stack/LinkStack.cpp
        03Stack/05_RearExpressionTest_Stack.cpp
)

add_executable(03Stack_linked 03Stack/03Stack_linked.cpp )
add_executable(01Queue 04queue/01_CQueueTest.cpp
        04queue/02_SQueueTest.cpp
        04queue/03_LinkQueueTest_withHead.cpp
        04queue/linkQueue.h
        04queue/04_LinkQueueTest_withoutHead.cpp
        03Stack/04_StackApplicationTest_Bracect.cpp)
add_executable(02_SQueueTest 04queue/02_SQueueTest.cpp)
add_executable(03_LinkQueue 04queue/03_LinkQueueTest_withHead.cpp)
add_executable(04_LinkQueueTest_withoutHead 04queue/04_LinkQueueTest_withoutHead.cpp)
add_executable(04_StackApplicationTest_Bracect 03Stack/04_StackApplicationTest_Bracect.cpp)
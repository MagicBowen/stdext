#include <gtest/gtest.h>
#include <stdext/SyncQueue.h>
#include <thread>
#include <atomic>

TEST(TestSyncQueue, should_two_thread)
{
    stdext::SyncQueue<int> queue;
    std::vector<int> result;

    auto producer = std::thread([&queue]
                                {
                                    for(int i = 0; i < 5; ++i)
                                    {
                                        queue.put(i);
                                    }
                                });

    auto consumer = std::thread([&queue, &result]
                                {
                                    while(true)
                                    {
                                        result.push_back(queue.take());
                                        if(result.size() >= 5) break;
                                    }
                                });

    producer.join();
    consumer.join();

    ASSERT_EQ((std::vector<int>{0, 1, 2, 3, 4}), result);
}

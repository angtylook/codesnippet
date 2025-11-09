// consumer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <csignal>
#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "cppkafka/cppkafka.h"

ABSL_FLAG(std::string, group_id, "0", "kafka consumer group id");

bool running = true;

int main(int argc, char* argv[]) {
  absl::ParseCommandLine(argc, argv);
  signal(SIGINT, [](int) { running = false; });
  cppkafka::Configuration config;
  config.set("metadata.broker.list", "localhost:9092");
  config.set("group.id", FLAGS_group_id.Get());
  config.set("enable.auto.commit", false);

  cppkafka::Consumer consumer(config);
  consumer.set_assignment_callback(
      [](const cppkafka::TopicPartitionList& partitions) {
        std::cout << "got assigned:" << partitions << std::endl;
      });
  consumer.set_revocation_callback(
      [](const cppkafka::TopicPartitionList& partitions) {
        std::cout << "got revoked:" << partitions << std::endl;
      });

  consumer.subscribe({"cppkafka"});
  while (running) {
    cppkafka::Message msg = consumer.poll();  // À­
    if (msg) {
      if (msg.get_error()) {
        if (!msg.is_eof()) {
          std::cout << "[+] Received error notification:" << msg.get_error()
                    << std::endl;
        }
      } else {
        if (msg.get_key()) {
          std::cout << msg.get_key() << " -> " << msg.get_payload() << std::endl;
        } else {
          std::cout << msg.get_payload() << std::endl;
        }
        consumer.commit(msg);
      }
    }
  }

  return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

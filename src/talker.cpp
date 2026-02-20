#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class Talker : public rclcpp::Node
{
public:
    Talker() : Node("talker"), count_(0)
    {
        // Declare parameter
        this->declare_parameter<std::string>("message_prefix", "Hello");

        publisher_ = this->create_publisher<std_msgs::msg::String>("/chatter", 10);

        timer_ = this->create_wall_timer(
            std::chrono::seconds(1),
            std::bind(&Talker::timer_callback, this)
        );
    }

private:
    void timer_callback()
    {
        std::string prefix;
        this->get_parameter("message_prefix", prefix);

        auto message = std_msgs::msg::String();
        message.data = prefix + ": " + std::to_string(count_);

        RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());

        publisher_->publish(message);
        count_++;
    }

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    int count_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Talker>());
    rclcpp::shutdown();
    return 0;
}

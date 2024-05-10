#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/accel.hpp"

class AccelPublisher : public rclcpp::Node
{
public:
    AccelPublisher() : Node("submarine_accel_publisher")
    {
        publisher_ = this->create_publisher<geometry_msgs::msg::Accel>("submarine_accel_data", 10);
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(500),
            std::bind(&AccelPublisher::publish_data, this));
    }

private:
    void publish_data()
    {
        auto message = geometry_msgs::msg::Accel();
        // Simulate data
        message.linear.x = 0.0;  // Example linear acceleration on x-axis
        message.linear.y = 0.0;  // Example linear acceleration on y-axis
        message.linear.z = -9.81;  // Simulated gravitational acceleration on z-axis

        message.angular.x = 0.1;  // Example angular acceleration on x-axis
        message.angular.y = 0.2;  // Example angular acceleration on y-axis
        message.angular.z = 0.3;  // Example angular acceleration on z-axis

        publisher_->publish(message);
        RCLCPP_INFO(this->get_logger(), "Publishing Mock Accel Data: Linear (%f, %f, %f), Angular (%f, %f, %f)",
                    message.linear.x, message.linear.y, message.linear.z,
                    message.angular.x, message.angular.y, message.angular.z);
    }

    rclcpp::Publisher<geometry_msgs::msg::Accel>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<AccelPublisher>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}


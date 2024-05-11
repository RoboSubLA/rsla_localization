#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/accel.hpp" // Include the Accel message header

class LocalizationListener : public rclcpp::Node
{
public:
  LocalizationListener()
  : Node("localization_listener")
  {
    subscription_ = this->create_subscription<geometry_msgs::msg::Accel>( // Change message type to Accel
        "/accel_topic", 10, // Change topic to your Accel topic
        std::bind(&LocalizationListener::topic_callback, this, std::placeholders::_1));
  }

private:
  void topic_callback(const geometry_msgs::msg::Accel::SharedPtr msg) const // Change message type to Accel
  {
    RCLCPP_INFO(this->get_logger(), "Heard acceleration: ['%f', '%f', '%f']",
                msg->linear.x, msg->linear.y, msg->linear.z); // Access linear acceleration components
    RCLCPP_INFO(this->get_logger(), "Heard angular acceleration: ['%f', '%f', '%f']",
                msg->angular.x, msg->angular.y, msg->angular.z); // Access angular acceleration components
  }
  rclcpp::Subscription<geometry_msgs::msg::Accel>::SharedPtr subscription_; // Change subscription type to Accel
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<LocalizationListener>());
  rclcpp::shutdown();
  return 0;
}


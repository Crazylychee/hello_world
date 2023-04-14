web.xml
<?xml version="1.0" encoding="UTF-8"?>

<web-app xmlns="http://xmlns.jcp.org/xml/ns/javaee"
xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
xsi:schemaLocation="http://xmlns.jcp.org/xml/ns/javaee
http://xmlns.jcp.org/xml/ns/javaee/web-app_4_0.xsd"
version="4.0"
metadata-complete="true">

<display-name>Welcome to Tomcat</display-name>
<description>
Welcome to Tomcat
</description>

  <!--ServLet-->
  <servlet>
    <servlet-name>hello</servlet-name>
    <servlet-class>com.lychee.servlet.Helloservlet</servlet-class>
  </servlet>
  <!--ServLet的清求路径-->
  <!--LocaLhost;8980/s1/heLLo/heLLo-->
  <servlet-mapping>
      <servlet-name>hello</servlet-name>
      <url-pattern>/*</url-pattern>
  </servlet-mapping>
  <servlet-mapping>
      <servlet-name>hello</servlet-name>
      <url-pattern>/hello2</url-pattern>
  </servlet-mapping>
  <servlet-mapping>
      <servlet-name>hello</servlet-name>
      <url-pattern>/hello3</url-pattern>
  </servlet-mapping>
  <servlet-mapping>
      <servlet-name>hello</servlet-name>
      <url-pattern>/hell04</url-pattern>
  </servlet-mapping>
  <servlet-mapping>
     <servlet-name>hello</servlet-name>
      <url-pattern>/hello5</url-pattern>
  </servlet-mapping>
  </web-app>
web.xml

package com.lychee.servlet;

import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.URLDecoder;
import java.net.URLEncoder;
/**
 * @author yc
 * @date 2023/4/9 10:41
 */
public class CookiesDemo extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {

        resp.setHeader("Content-type", "text/html;charset=UTF-8");
        req.setCharacterEncoding("UTF-8");
        resp.setCharacterEncoding("UTF-8");
        Cookie[] cookies = req.getCookies();
        PrintWriter out = resp.getWriter();

        if (cookies!=null){
            out.write("你上一次访问的时间是：");

            for (int i=0;i<cookies.length;i++){
                Cookie cookie = cookies[i];
                //获取cookie的名字
                if (cookie.getName().equals("name")){
                    out.write(URLDecoder.decode(cookie.getValue(),"UTF-8"));
                }
            }
        }else{
            out.write("这是您第一次访问本站");
        }
        Cookie cookie = new Cookie("name", URLEncoder.encode("小明","utf-8"));
        resp.addCookie(cookie);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doGet(req, resp);
    }
}

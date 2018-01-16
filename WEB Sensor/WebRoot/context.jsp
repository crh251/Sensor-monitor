<%@ page language="java" import="java.util.*,com.*" pageEncoding="utf-8"%>


<%
	ArrayList<String> list = GetData.DaoForMySql();
	String Temperature = list.get(0);
	String Humidity = list.get(1);
	String Dust = list.get(2);
	String Time = list.get(3);
%>


<%
	//设置输出信息的格式及字符集  
	response.setContentType("text/xml; charset=UTF-8");
	response.setHeader("Cache-Control", "no-cache");

	String message = "<response>\n" + "<Temperature>" + Temperature + "</Temperature>\n" + "<Humidity>" + Humidity
			+ "</Humidity>\n" + "<Dust>" + Dust + "</Dust>\n" + "<Time>" + Time + "</Time>\n" + "</response>";

	//System.out.println(message);

	out.print(message);
%>


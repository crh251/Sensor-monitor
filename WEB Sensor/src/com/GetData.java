package com;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;

public class GetData {

	private static Connection conn = JdbcUtils.getConnection();
	private static String sql = "select * from sensor_data where Time = (select max(Time) from sensor_data) and TimeStampDiff(SECOND, Time, now()) <= 10";

	@SuppressWarnings("finally")
	public static ArrayList<String> DaoForMySql() {
		ResultSet rs = null;
		Statement stmt = null; // 创建Statement对象
		ArrayList<String> list = new ArrayList<>();
		try {
			stmt = conn.createStatement();
			rs = stmt.executeQuery(sql);
			if (!rs.next()) {
				// 查询结果为空
				list.add("--");
				list.add("--");
				list.add("--");
				list.add("--");
			} else {
				// 查询结果正常
				list.add(rs.getString(1));
				list.add(rs.getString(2));
				list.add(rs.getString(3));
				String Time = rs.getObject(4).toString();
				list.add(Time.substring(0, Time.length() - 2));
			}
			rs.close();
			stmt.close();
		} catch (Exception e) {
			System.out.println("fuction DaoForMySql occure Exception!");
			e.printStackTrace();
		} finally {
//			System.out.println(list.toString());
			return list;
		}
	}
}

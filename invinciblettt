package tttp;

import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class tttc {

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	static String player_first="none"; //yes/no/none | default: none
	static String exit_after_round=""; //yes | default: ""
	static String message_after_end="yes"; //yes | default: yes

	static String a=".";
	static String b=" ";
	static String s="     ";
	static String c=", ";
	static String win_2="-*+*-";

	static String message_a_1="Algorithm choose position ";
	static String message_s_11="Please choose a position.";
	static String message_s_12="Use following format (Example): A2 (<Letter><Number>)";
	static String message_s_2="You chose position ";
	static String message_s_3="The system settings are incorrect. Use the following format: player_first=\"<yes/no>\"";
	static String message_new_round="A new round has started.";
	static String error_1="Your entry is invalid. ";
	static String win="and wins the game.";
	static String equal="Nobody won the game.";
	static String restart_yes="Since you started this round, the algorithm now begins.";
	static String restart_no="Since the algorithm started this round you start now.";
	static String final_message="The game will now end";
	static String fatal_error="System error, restart the program.";

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	static int turn=0, turn_2=0, turn_3;
	static String test, temp_new_a_p="", temp_new_b_p="", temp_new_a_f="", temp_m_x="none";

	static int algorithm_1, algorithm_2;

	static int random_start, random_pf_2, random_x, random_y, randomizer_1=2, randomizer_2=3;

	static int [][]m={{0,0,0}, {0,0,0}, {0,0,0},};

	static List<String> type_a = Arrays.asList("A","a","1");
	static List<String> type_b = Arrays.asList("B","b","2");
	static List<String> type_c = Arrays.asList("C","c","3");
	static List<String> allowed_pos2 = Arrays.asList("1","2","3");

	public static void main(String[] args) {
			if (player_first=="none") {
				random_start=(int)(Math.random()*randomizer_1);
				if (random_start==0) {
					player_first="no";
					random_pf_2=1;
				} else {
					player_first="yes";
					random_pf_2=1;
				}
			}
			if (player_first=="no") {
				for (int i_1=1;i_1>0;) {
					randomizer();
					if (random_x!=1&&random_y!=1) {
						m[random_x][random_y]=1;break;
					}
				}
				String message_r_x_1="";
				switch (random_x) {
					case 0: message_r_x_1="A";break;
					case 2: message_r_x_1="C";break;
					default: System.out.println("X301 "+fatal_error);break;
				}
				matrix_tutorial();
				System.out.println("C001: "+message_a_1+message_r_x_1+(random_y+1)+a+"\rC002: "+message_s_11);
			} else if (player_first=="yes") {
				matrix_tutorial();
				System.out.println("C050: "+message_s_11);
			} else {
				System.err.println("C049: "+message_s_3);
			}
			System.out.println("C003: "+message_s_12);
			if (player_first=="yes"||player_first=="no") {
				algorithm_1++; 
			}
			for (int i_2=1;i_2>0;) {
				if (algorithm_1==1) {
					for (int i_5=1;i_5>0;) {
						Scanner imput_scanner=new Scanner(System.in);
						String imput_user=imput_scanner.nextLine();
						if (imput_user.length()==2) {
							String imput_u_1=imput_user.substring(0,1);
							String imput_u_2=imput_user.substring(1,2);
								if ((type_a.contains(imput_u_1)||type_b.contains(imput_u_1)||type_c.contains(imput_u_1))&&allowed_pos2.contains(imput_u_2)) {
									temp_m_x=imput_u_2;
									if (type_a.contains(imput_u_1)) {
										imput_u_1="0";
									}
									if (type_b.contains(imput_u_1)) {
										imput_u_1="1";
									}
									if (type_c.contains(imput_u_1)) {
										imput_u_1="2";
									}
									int imput_i_u_1=Integer.parseInt(imput_u_1);
									int imput_i_u_2=Integer.parseInt(imput_u_2);
									if (m[imput_i_u_1][imput_i_u_2-1]==0) {
										m[imput_i_u_1][imput_i_u_2-1]=2;
										String message_i_i_u_1 = "";
										switch (imput_i_u_1) {
											case 0: message_i_i_u_1="A";break;
											case 1: message_i_i_u_1="B";break;
											case 2: message_i_i_u_1="C";break;
											default: System.out.println("X302 "+fatal_error);break;
										}
										algorithm_1--;algorithm_2++;
										matrix_status();
										System.out.println("B004: "+message_s_2+message_i_i_u_1+temp_m_x+".");break;
										} else {
											System.out.println("B005: "+error_1+message_s_12);
										}
									} else {
										System.out.println("B048: "+error_1+message_s_12);
									}
								} else {
									System.out.println("B051: "+error_1+message_s_12);
								}
							}
						}
				int m_sum=0;
				for (int sum_x=0; sum_x<3; sum_x++) {
					for (int sum_y=0; sum_y<3; sum_y++) {
						m_sum=m_sum+m[sum_x][sum_y];
					}
				}
				for (int i_6=1;i_6>0;) { 
					if (m_sum>=13&&player_first=="yes") {
						System.out.println(win_2+"\rG065: "+equal+"\r"+win_2);
						turn_2=1;turn=1;test="on";game_end();break;
					}
					if (m_sum>=12&&player_first=="no") {
						System.out.println(win_2+"\rG067: "+equal+"\r"+win_2);
						turn_2=1;game_end();break;
					}
					if (algorithm_2==1) { 
						if (((m[0][2]==1&&m[2][0]==1)||(m[0][0]==1&&m[2][2]==1)||(m[1][0]==1&&m[1][2]==1)||(m[0][1]==1&&m[2][1]==1))&&m[1][1]==0) {
						      m[1][1]=1;System.out.println(win_2+"\rA006: "+message_a_1+"B2");
						      turn=1;win_mp1();
						} else if (((m[0][0]==1&&m[2][0]==1)||(m[1][1]==1&&m[1][2]==1))&&m[1][0]==0) {
									 m[1][0]=1;System.out.println(win_2+"\rA007: "+message_a_1+"B1");
									 turn=1;win_mp1();
						} else if (((m[0][2]==1&&m[2][2]==1)||(m[1][0]==1&&m[1][1]==1))&&m[1][2]==0) {
									 m[1][2]=1;System.out.println(win_2+"\rA008: "+message_a_1+"B3");
									 turn=1;win_mp1();
						} else if (((m[0][0]==1&&m[0][2]==1)||(m[1][1]==1&&m[2][1]==1))&&m[0][1]==0) {
									 m[0][1]=1;System.out.println(win_2+"\rA009: "+message_a_1+"A2");
									 turn=1;win_mp1();
						} else if (((m[2][0]==1&&m[2][2]==1)||(m[0][1]==1&&m[1][1]==1))&&m[2][1]==0) {
									 m[2][1]=1;System.out.println(win_2+"\rA010: "+message_a_1+"C2");
									 turn=1;win_mp1();
						} else if (((m[1][0]==1&&m[2][0]==1)||(m[0][1]==1&&m[0][2]==1)||(m[1][1]==1&&m[2][2]==1))&&m[0][0]==0) {
									 m[0][0]=1;System.out.println(win_2+"\rA011: "+message_a_1+"A1");
									 turn=1;win_mp1();
						} else if (((m[0][0]==1&&m[0][1]==1)||(m[1][2]==1&&m[2][2]==1)||(m[2][0]==1&&m[1][1]==1))&&m[0][2]==0) {
									 m[0][2]=1;System.out.println(win_2+"\rA012: "+message_a_1+"A3");
									 turn=1;win_mp1();
						} else if (((m[0][2]==1&&m[1][2]==1)||(m[2][0]==1&&m[2][1]==1)||(m[0][0]==1&&m[1][1]==1))&&m[2][2]==0) {
									 m[2][2]=1;System.out.println(win_2+"\rA013: "+message_a_1+"C3");
									 turn=1;win_mp1();
						} else if (((m[2][1]==1&&m[2][2]==1)||(m[0][0]==1&&m[0][1]==1)||(m[0][2]==1&&m[1][1]==1))&&m[2][0]==0) {
									 m[2][0]= 1;System.out.println(win_2+"\rA014: "+message_a_1+"C1");
									 turn=1;win_mp1();
						} else {
							if (((m[0][2]==2&&m[2][0]==2)||(m[0][0]==2&&m[2][2]==2)||(m[1][0]==2&&m[1][2]==2)||(m[0][1]==2&&m[2][1]==2))&&m[1][1]==0) {
								m[1][1]=1;System.out.println("A015: "+message_a_1+"B2.");
							} else if (((m[0][0]==2&&m[2][0]==2)||(m[1][1]==2&&m[1][2]==2))&&m[1][0]==0) {
								m[1][0]=1;System.out.println("A016: "+message_a_1+"B1.");
							} else if (((m[0][2]==2&&m[2][2]==2)||(m[1][0]==2&&m[1][1]==2))&&m[1][2]==0) {
								m[1][2]=1;System.out.println("A017: "+message_a_1+"B3.");
							} else if (((m[0][0]==2&&m[0][2]==2)||(m[1][1]==2&&m[2][1]==2))&&m[0][1]==0) {
								m[0][1]=1;System.out.println("A018: "+message_a_1+"A2.");
							} else if (((m[2][0]==2&&m[2][2]==2)||(m[0][1]==2&&m[1][1]==2))&&m[2][1]==0) {
								m[2][1]=1;System.out.println("A019: "+message_a_1+"C2.");
							} else if (((m[1][0]==2&&m[2][0]==2)||(m[0][1]==2&&m[0][2]==2)||(m[1][1]==2&&m[2][2]==2))&&m[0][0]==0) {
								m[0][0]=1;System.out.println("A020: "+message_a_1+"A1.");
							} else if (((m[0][0]==2&&m[0][1]==2)||(m[1][2]==2&&m[2][2]==2)||(m[2][0]==2&&m[1][1]==2))&&m[0][2]==0) {
								m[0][2]=1;System.out.println("A021: "+message_a_1+"A3.");
							} else if (((m[0][2]==2&&m[1][2]==2)||(m[2][0]==2&&m[2][1]==2)||(m[0][0]==2&&m[1][1]==2))&&m[2][2]==0) {
								m[2][2]=1;System.out.println("A022: "+message_a_1+"C3.");
							} else if (((m[2][1]==2&&m[2][2]==2)||(m[0][0]==2&&m[0][1]==2)||(m[0][2]==2&&m[1][1]==2))&&m[2][0]==0) {
								m[2][0]=1;System.out.println("A023: "+message_a_1+"C1.");
							} else if (m[1][1]==2&&m[0][0]==2&&m[2][2]==1) { 
									m[0][2]=1;System.out.println("A052: "+message_a_1+"A3.");
							} else if (m[1][1]==2&&m[0][2]==2&&m[2][0]==1) { 
									m[2][2]=1;System.out.println("A053: "+message_a_1+"C3.");
							} else if (m[1][1]==2&&m[2][2]==2&&m[0][0]==1) {
									m[2][0]=1;System.out.println("A054: "+message_a_1+"C1.");
							} else if (m[1][1]==2&&m[2][0]==2&&m[0][2]==1) { 
									m[0][0]=1;System.out.println("A055: "+message_a_1+"A1.");
							} else {
								for (int i_7=1;i_7>0;) { 
									if(m_sum==3&&m[1][1]==2&&player_first=="no") {
										if (m[0][0]==1) { 
											m[2][2]=1;System.out.println("A026: "+message_a_1+"C3.");break;
										}
										if (m[0][2]==1) { 
											m[2][0]=1;System.out.println("A027: "+message_a_1+"C1.");break;
										}
										if (m[2][2]==1) {
											m[0][0]=1;System.out.println("A028: "+message_a_1+"A1.");break;
										}
										if (m[2][0]==1) { 
											m[0][2]=1;System.out.println("A029: "+message_a_1+"A3.");break;
										}
									}
									if ((m_sum==6&&((m[0][0]==1&&m[2][2]==1)||(m[0][2]==1&&m[2][0]==1)))&&m[1][1]==2) {
										if(m[0][0]==0&&m[0][1]==0&&m[1][0]==0) {
										   m[0][0]=1;System.out.println("A030: "+message_a_1+"A1.");break;
										} else {
										   m[2][2]=1;System.out.println("A031: "+message_a_1+"C3.");break;
										}
									}
									if (m_sum==3) { 
										if (m[0][0]==1&&(m[0][2]==2||m[2][0]==2)) { 
											m[2][2]=1;System.out.println("A033: "+message_a_1+"C3.");break;
										}
										if (m[0][2]==1&&(m[0][0]==2||m[2][2]==2)) { 
											m[2][0]=1;System.out.println("A034: "+message_a_1+"C1.");break;
										}
										if (m[2][2]==1&&(m[0][2]==2||m[2][0]==2)) {
											m[0][0]=1;System.out.println("A035: "+message_a_1+"A1.");break;
										}
										if (m[2][0]==1&&(m[0][0]==2||m[2][2]==2)) {
											m[0][2]=1;System.out.println("A036: "+message_a_1+"A3.");break;
										}
										if ((m[0][0]==1&&m[2][2]==2)||m[0][2]==1&&m[2][0]==2||m[2][2]==1&&m[0][0]==2||m[2][0]==1&&m[0][2]==2) { 
											 m[1][1]=1;System.out.println("A037: "+message_a_1+"B2.");break;
										}
										if (m[0][1]==2||m[1][2]==2||m[2][1]==2||m[1][0]==2) {
											m[1][1]=1;System.out.println("A039: "+message_a_1+"B2.");break;
										}
									}
									if (m_sum==6) {
										if(m[1][1]==1) { 
											if (m[0][0]==1&&m[2][2]==2&&m[0][2]==0&&m[0][1]==0) {
												m[0][2]=1;System.out.println("A040: "+message_a_1+"A3.");break;
											}
											if (m[0][0]==1&&m[2][2]==2&&m[0][2]==0&&m[0][1]==2) {
												m[2][0]=1;System.out.println("A041: "+message_a_1+"C1.");break;
											}
											if (m[0][2]==1&&m[2][0]==2&&m[2][2]==0&&m[1][2]==0) {
												m[2][2]=1;System.out.println("A042: "+message_a_1+"C3.");break;
											}
											if (m[0][2]==1&&m[2][0]==2&&m[2][2]==0&&m[1][2]==2) {
												m[0][0]=1;System.out.println("A043: "+message_a_1+"A1.");break;
											}
											if (m[2][2]==1&&m[0][0]==2&&m[0][2]==0&&m[2][1]==0) {
												m[2][0]=1;System.out.println("A044: "+message_a_1+"C1.");break;
											}
											if (m[2][2]==1&&m[0][0]==2&&m[0][2]==0&&m[2][1]==2) {
												m[0][2]=1;System.out.println("A045: "+message_a_1+"A3.");break;
											}
											if (m[2][0]==1&&m[0][2]==2&&m[0][0]==0&&m[1][0]==0) {
												m[0][0]=1;System.out.println("A046: "+message_a_1+"A1.");break;
											}
											if (m[2][0]==1&&m[0][2]==2&&m[0][0]==0&&m[1][0]==2) {
												m[2][2]=1;System.out.println("A047: "+message_a_1+"C3.");break;
											}
										}
									}
									if (m_sum==2&&m[1][1]==0) { 
										m[1][1]=1;
										System.out.println("K201: "+message_a_1+"B1.");break;
									}
									if (m_sum==2&&m[1][1]==2) {
										for (int i_8=1;i_8>0;) {
											randomizer();
											if (random_x!=1&&random_y!=1) { 
												m[random_x][random_y]=1;
												switch_a();
												System.out.println("K200: "+message_a_1+temp_new_a_f+(random_y+1)+a);break; 
											}
										}break;
									}
									if (m_sum==5&&m[1][1]==1&&((m[0][0]==2&&m[2][2]==2)||(m[2][0]==2&&m[0][2]==2))) { 
										for (int i_9=1;i_9>0;) { 
											randomizer(); 
											if ((random_x==0||random_x==2)&&(random_y!=0&&random_y!=2)) { 
												m[random_x][random_y]=1;
												switch_a();
												System.out.println("K202: "+message_a_1+temp_new_a_f+(random_y+1)+a);break;
											}
										}break;
									}
									if (turn_2==1) {
										break; 
									}
									for (int i_10=1;i_10>0;) {
										randomizer();
										if (test=="on") {
											if (random_x!=1&&random_y!=1) {
												m[random_x][random_y]=1;
												turn_3=1;
											}
										}
										if (test!="on") {
											if (m[random_x][random_y]==0) { 
												m[random_x][random_y]=1;
												turn_3=1;
											}
										}
										if (turn_3==1) {
											switch_a();
											System.out.println("E038: "+message_a_1+temp_new_a_f+(random_y+1)+temp_new_b_p);
											turn_3=0;break;
										}
									}break;
								}
							}
							if (random_x==0) { 
								temp_new_a_p="A";
							}
							if (random_x==1) {
								temp_new_a_p="B";
							}
							if (random_x==2) {
								temp_new_a_p="C";
							} 
							matrix_status();
							System.out.println("D024: "+message_s_11);
							algorithm_2--;algorithm_1++;break; 
						}
						matrix_status();
						System.out.println("D025: "+message_s_11);
						algorithm_2--;algorithm_1++;break; 
					}
				}
			}
		}
	private static void game_end() {
		random_pf_2=0;
		if (exit_after_round=="yes") {
			if (message_after_end=="yes") {
				System.out.println("Z100: "+final_message);
			}
			System.exit(0);
		} else {
			System.out.println("F064: "+message_new_round);
		}
		clear();
		if (player_first=="yes") {
			System.out.println("H068: "+restart_yes);
			if (turn==1) {
				for (int i_1=1;i_1>0;) {
					randomizer();
					if (random_x!=1&&random_y!=1) {
						m[random_x][random_y]=1;
						if (test=="on") {
							clear();
						}
						turn=0;turn_2=0;break;
					}
				}
			}
			player_first="no";
			random_pf_2=1;
		}
		if (player_first=="no"&&random_pf_2==0) {
			player_first="yes";
			System.out.println("H070: "+restart_no);
		}
		random_pf_2=0;
	}
	private static void matrix_status() {
		System.out.println("\r"+s+m[0][0]+b+"┃"+b+m[0][1]+b+"┃"+b+m[0][2]+"\r"+s+"━━┃"+"━━━┃"+"━━"+"\r"+s+m[1][0]+b+"┃"+b+m[1][1]+b+"┃"+b+m[1][2]+"\r"+s+"━━┃"+"━━━┃"+"━━"+"\r"+s+m[2][0]+b+"┃"+b+m[2][1]+b+"┃"+b+m[2][2]+"\r\r");
	}
	private static void matrix_tutorial() {
		System.out.println("\r A → "+m[0][0]+b+"┃"+b+m[0][1]+b+"┃"+b+m[0][2]+"\r"+ s+"━━┃"+"━━━┃"+"━━"+"\r"+" B → "+m[1][0]+b+"┃"+b+m[1][1]+b+"┃"+b+m[1][2]+"\r"+s+"━━┃"+"━━━┃"+"━━"+"\r"+" C → "+m[2][0]+b+"┃"+b+m[2][1]+b+"┃"+b+m[2][2]+"\r"+s+"↑   ↑   ↑\r"+s+"1   2   3\r");
	}
	private static void randomizer() {
		random_x=(int)(Math.random()*randomizer_2);
		random_y=(int)(Math.random()*randomizer_2);
	}
	private static void win_mp1() {
		System.out.print(win+"\r"+win_2+"\r");
		game_end();
	}
	private static void clear() {
		for (int clear_x=0; clear_x<3; clear_x++) {
			for (int clear_y=0; clear_y<3; clear_y++) {
				m[clear_x][clear_y]=0;
			}
		}
	}
	private static void switch_a() {
		switch (random_x) {
			case 0: temp_new_a_f="A";break;
			case 1: temp_new_a_f="B";break;
			case 2: temp_new_a_f="C";break;
			default: System.out.println("X303 "+fatal_error);break;
		}
	}
}

import java.io.*;

class Main {

	private static final String START = "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
	private static final String PATTERN = "____";
	private static final String QUESTION = "\"재귀함수가 뭔가요?\"\n";
	private static final String ANSWER_ONE = "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
	private static final String ANSWER_TWO = "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
	private static final String ANSWER_THREE = "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
	private static final String ANSWER_FINAL = "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
	private static final String END = "라고 답변하였지.\n";

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		int n = Integer.parseInt(br.readLine());
		sb.append(START).append(solution(0, n));
		bw.write(sb.toString());
		bw.close();
		br.close();
	}

	private static String solution(int start, int end) {
		StringBuilder sb = new StringBuilder();
		StringBuilder prefix = new StringBuilder();
		prefix.append(PATTERN.repeat(Math.max(0, start)));
		sb.append(prefix).append(QUESTION);
		if (start == end)
			sb.append(prefix).append(ANSWER_FINAL);
		else {
			sb.append(prefix).append(ANSWER_ONE)
				.append(prefix).append(ANSWER_TWO)
				.append(prefix).append(ANSWER_THREE)
				.append(solution(start + 1, end));
		}
		return sb.append(prefix).append(END).toString();
	}

}

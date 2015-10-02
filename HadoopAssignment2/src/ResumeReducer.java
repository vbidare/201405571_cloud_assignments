import java.io.IOException;

import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

public class ResumeReducer extends
		Reducer<Text, Text, Text, Text> {
	protected void reduce(Text key, Iterable<Text> values,
			Context context) throws IOException, InterruptedException {
		StringBuilder sb = new StringBuilder();
		for (Text value : values) {
			sb.append(value.toString().split(":")[1]).append(',');
		}
		context.write(new Text (""), new Text (sb.toString()));
	}
}
import java.io.IOException;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.lib.input.FileSplit;

public class ResumeMapper extends
		Mapper<LongWritable, Text, Text, Text> {

	protected void map(LongWritable key, Text value, Context context)
			throws IOException, InterruptedException {
		String line = value.toString().trim();
		
		String fileName = ((FileSplit) context.getInputSplit()).getPath().getName();
		if (line.contains(":")) {
			context.write (new Text(fileName), new Text (line));
		}
	}
}
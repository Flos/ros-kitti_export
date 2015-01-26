/*
 * dataset.h
 *
 *  Created on: 20.01.2015
 *      Author: fnolden
 */

//own
#include <common/serialization/camera_list.h>
#include <common/serialization/tf.h>
#include <common/serialization/file_list.h>
#include <string>
#include <sstream>
#include <dirent.h>

#ifndef SRC_GUI_KITTI_DATASET_H_
#define SRC_GUI_KITTI_DATASET_H_

namespace kitti {

struct Paths{
	std::string config_file;

	std::string tf_velodyne_to_cam0;
	std::string camera_calib_file;

	std::string root_data_path;
	std::string pcl_data;
	String_list camera_data;
};

class Dataset {
public:
	Dataset();
	Dataset(std::string config);
	bool init(std::string config);
	bool load_config(std::string config);

	bool check();

	virtual ~Dataset();

	Paths path;

	Camera_list camera_list;
	std::vector<String_list> camera_file_list;
	String_list pointcloud_file_list;
	Tf velodyne_to_cam0;

private:
	bool valid;

protected:
	void extract_string(std::istringstream& in, std::string &string);
	bool get_files(std::string path, String_list &list);
	bool load_cameras();
	bool load_camera_files();
	bool load_velodyne_to_cam_tf();
	bool load_pointcloud_files();
};

} /* namespace kitti */

#endif /* SRC_GUI_KITTI_DATASET_H_ */
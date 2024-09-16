# ByteByteGo System Design



##  Scale from zero to millions of users



### Single Server Setup:



![Figure 2](https://bytebytego.com/_next/image?url=%2Fimages%2Fcourses%2Fsystem-design-interview%2Fscale-from-zero-to-millions-of-users%2Ffigure-1-2-GPY73ZNO.png&w=1080&q=75)



- **All-in-One Server Configuration:**
  
  - The entire system—including the web application, database, and cache—is hosted on a single server.
  - This simplifies the initial setup when building a complex system from scratch.
  
- **Request Flow Overview:**
  1. **DNS Resolution:**
     - Users access the website via a domain name like `api.mysite.com`.
     - A third-party DNS service resolves this domain to an IP address.
  2. **IP Address Retrieval:**
     - The browser or mobile app receives the IP address (e.g., `15.125.23.214`).
  3. **HTTP Request:**
     - An HTTP request is sent directly to the web server using the IP address.
  4. **Server Response:**
     - The web server returns HTML pages or JSON data for rendering in the client.

- **Traffic Sources:**
  - **Web Application:**
    - Uses server-side languages like Java or Python for business logic and data handling.
    - Employs client-side languages like HTML and JavaScript for the user interface.
  - **Mobile Application:**
    - Communicates with the web server over HTTP.
    - Utilizes JSON for API responses due to its simplicity and readability.

- **Example of a JSON API Response:**
  - **Endpoint:** `GET /users/12` retrieves information for the user with `id = 12`.
  - **Sample Response:**
    ```json
    {
      "id": 12,
      "firstName": "John",
      "lastName": "Smith",
      "address": {
        "streetAddress": "21 2nd Street",
        "city": "New York",
        "state": "NY",
        "postalCode": 10021
      },
      "phoneNumbers": [
        "212 555-1234",
        "646 555-4567"
      ]
    }
    ```





### Database

![Figure 3](https://bytebytego.com/_next/image?url=%2Fimages%2Fcourses%2Fsystem-design-interview%2Fscale-from-zero-to-millions-of-users%2Ffigure-1-3-2P4MNG7C.png&w=1200&q=75)



**Database Scaling and Selection:**

- **Scaling with Multiple Servers:**
  - As the user base grows, a single server becomes insufficient.
  - Separating services allows independent scaling:
    - **Web/Mobile Server (Web Tier):** Handles web and mobile traffic.
    - **Database Server (Data Tier):** Manages data storage and retrieval.

- **Choosing the Right Database:**
  - **Relational Databases (RDBMS/SQL):**
    - Examples: MySQL, Oracle, PostgreSQL.
    - Data is stored in tables with rows and columns.
    - Supports SQL queries and join operations across tables.
    - Well-established with over 40 years of reliability.
  - **Non-Relational Databases (NoSQL):**
    - Examples: CouchDB, Neo4j, Cassandra, HBase, Amazon DynamoDB.
    - Categorized into key-value stores, graph stores, column stores, and document stores.
    - Generally do not support join operations.
    - Designed for specific use cases and data models.

- **When to Use Non-Relational Databases:**
  - **Super-Low Latency Requirements:**
    - Applications needing extremely fast read/write operations.
  - **Unstructured or Non-Relational Data:**
    - Data that doesn't fit neatly into tables.
  - **Simple Serialization Needs:**
    - Primarily storing and retrieving data in formats like JSON, XML, or YAML.
  - **Massive Data Volume:**
    - Handling large-scale data that surpasses traditional database capacities.

- **Key Considerations:**
  - **Relational Databases** are generally the default choice due to their maturity and robustness.
  - **Non-Relational Databases** are suitable for specialized needs where relational databases may not perform optimally.
  - Assess your application's specific requirements to choose the most appropriate database solution.





### Vertical Scaling vs Horizontal Scaling:

- **Vertical Scaling ("Scale Up"):**
  - **Definition:** Adding more resources (CPU, RAM, etc.) to a single server to handle increased load.
  - **Advantages:**
    - Simple to implement when dealing with low traffic.
  - **Limitations:**
    - **Resource Limits:** There's a maximum capacity to how much you can upgrade a single server.
    - **Lack of Redundancy:** No failover protection; if the server fails, the entire application becomes unavailable.

- **Horizontal Scaling ("Scale Out"):**
  - **Definition:** Adding more servers to your infrastructure to distribute the load across multiple machines.
  - **Advantages:**
    - **Scalability:** Can handle increased traffic by simply adding more servers.
    - **Redundancy:** Provides failover capabilities; if one server goes down, others continue to serve the application.
  - **Preferred for Large Applications:** Overcomes the limitations associated with vertical scaling.

- **Introduction of Load Balancer:**
  - **Problem Without Load Balancer:**
    - Direct connection between users and a single web server creates a single point of failure.
    - High traffic can overwhelm the server, leading to slow responses or connection failures.
  - **Solution: Load Balancing:**
    - Distributes incoming network traffic across multiple servers.
    - **Benefits:**
      - Improves application reliability and uptime.
      - Enhances performance by preventing any single server from becoming a bottleneck.
      - Provides a better user experience through faster response times and increased availability.



### Load balancer

![Figure 4](https://bytebytego.com/_next/image?url=%2Fimages%2Fcourses%2Fsystem-design-interview%2Fscale-from-zero-to-millions-of-users%2Ffigure-1-4-2EGRRANZ.png&w=1200&q=75)



**Implementing a Load Balancer:**

- **Purpose and Function:**
  - A load balancer evenly distributes incoming traffic across multiple web servers in a load-balanced set.
  - Enhances reliability and availability by preventing any single server from becoming a point of failure.

- **Operational Overview:**
  - **Client Connection:**
    - Users connect directly to the public IP address of the load balancer.
    - Web servers are no longer directly accessible by clients, increasing security.
  - **Internal Communication:**
    - The load balancer communicates with web servers using private IPs, which are only reachable within the same network.
    - Private IPs are not accessible over the internet, reducing external exposure.

- **Benefits of Using a Load Balancer:**
  - **Failover Support:**
    - If one web server goes offline, the load balancer redirects traffic to other available servers.
    - Prevents the entire website or application from going down due to a single server failure.
  - **Scalability:**
    - As traffic increases, more web servers can be added to the pool.
    - The load balancer automatically includes new servers in its distribution of incoming requests.
  - **Improved Security:**
    - Direct client access to web servers is restricted.
    - Reduces the attack surface by exposing only the load balancer's public IP.

- **Enhancements to the Web Tier:**
  - **Increased Availability:**
    - Multiple servers ensure that services remain available even if one server fails.
  - **Load Management:**
    - Balances the workload to prevent any single server from becoming overwhelmed.
    - Provides a smoother user experience with reduced latency and downtime.

- **Addressing the Data Tier:**
  - The current setup uses a single database server, which lacks failover and redundancy.
  - **Next Steps:**
    - Implement database replication to enhance the data tier.
    - Replication will provide redundancy and improve the resilience of the database against failures.





### Database replication



![Figure 5](https://bytebytego.com/images/courses/system-design-interview/scale-from-zero-to-millions-of-users/figure-1-5-TJLQVE5N.svg)



**Database Replication Overview:**

- **Definition:**
  - Database replication involves copying and maintaining database objects in multiple databases within a distributed system.
  - Typically utilizes a **master-slave** architecture:
    - **Master Database:** Handles all write operations (insert, update, delete).
    - **Slave Databases:** Receive copies of data from the master and handle read operations.

- **Master-Slave Model Details:**
  - **Write Operations:**
    - Only performed on the master database.
  - **Read Operations:**
    - Distributed across multiple slave databases.
    - Enhances read performance due to parallel processing.
  - **Read-Write Ratio:**
    - Most applications have a higher read-to-write ratio.
    - Justifies the use of multiple slave databases to handle read load.

- **Advantages of Database Replication:**
  - **Better Performance:**
    - Parallel processing of read queries across slaves improves response times.
  - **Reliability:**
    - Data is preserved across multiple servers.
    - Protects against data loss from hardware failures or natural disasters.
  - **High Availability:**
    - Maintains website operation even if one database goes offline.
    - Users can still access data from other available database servers.

- **Handling Database Failures:**
  - **Slave Database Failure:**
    - Read operations are temporarily redirected to the master or other slave databases.
    - A new slave database is provisioned to restore redundancy.
  - **Master Database Failure:**
    - A slave database is promoted to become the new master.
    - All database operations (reads and writes) continue on the new master.
    - A replacement slave database is set up to maintain replication.
    - **Note:** Promoting a new master can be complex due to potential data lag; may require data recovery procedures.

- **Updated System Design with Load Balancer and Database Replication (Refer to Figure 6):**
  
- ![Figure 6](https://bytebytego.com/_next/image?url=%2Fimages%2Fcourses%2Fsystem-design-interview%2Fscale-from-zero-to-millions-of-users%2Ffigure-1-6-L2YNDDKF.png&w=1080&q=75)
  1. **DNS Resolution:**
     - The user obtains the IP address of the load balancer from DNS.
  2. **Connection Established:**
     - The user connects to the load balancer using this IP address.
  3. **Request Distribution:**
     - The load balancer routes the HTTP request to either Server 1 or Server 2.
  4. **Read Operations:**
     - Web servers retrieve user data from a slave database.
  5. **Write Operations:**
     - Web servers send data-modifying requests (write, update, delete) to the master database.

- **Next Steps for Performance Improvement:**
  - **Add a Cache Layer:**
    - Implement caching to reduce database load and improve response times.
  - **Utilize a Content Delivery Network (CDN):**
    - Offload static content (JavaScript, CSS, images, videos) to a CDN for faster content delivery to users globally.





### Cache

![Figure 7](https://bytebytego.com/images/courses/system-design-interview/scale-from-zero-to-millions-of-users/figure-1-7-GGNXNZX6.svg)

**Cache Tier Overview:**

- **Purpose of the Cache Tier:**
  - Acts as a temporary data storage layer that is significantly faster than the database.
  - Enhances system performance by reducing the workload on the database.
  - Allows independent scaling of the cache layer.

- **Cache Operation Workflow:**
  - When a web server receives a request, it first checks the cache for the required data.
    - **Cache Hit:** If the data is found, it sends the data back to the client immediately.
    - **Cache Miss:** If not, it queries the database, stores the retrieved data in the cache, and then responds to the client.
  - This strategy is known as a **read-through cache**.
  - Different caching strategies can be applied based on data type, size, and access patterns.

- **Interacting with Cache Servers:**
  - Most cache servers provide APIs compatible with common programming languages.
  - **Example using Memcached API:**
    ```python
    SECONDS = 1
    cache.set('myKey', 'hi there', 3600 * SECONDS)
    cache.get('myKey')
    ```

**Considerations for Using Cache:**

- **When to Use Cache:**
  - Ideal for data that is read frequently but modified infrequently.
  - Not suitable for persisting critical data, as cached data is stored in volatile memory and can be lost if the server restarts.

- **Expiration Policy:**
  - Implementing an expiration policy helps manage memory and data freshness.
    - Avoid setting expiration too short to prevent frequent database reloads.
    - Avoid setting expiration too long to prevent serving stale data.
  - Upon expiration, data is removed from the cache.

- **Consistency Between Cache and Data Store:**
  - Challenges arise because cache updates and database writes are not part of a single transaction.
  - Inconsistencies can occur, especially when scaling across multiple regions.
  - Maintaining synchronization is critical for data accuracy.

- **Mitigating Failures and Single Points of Failure (SPOF):**
  - A single cache server can be a SPOF, risking system availability if it fails.
  - **Solutions:**
    - Deploy multiple cache servers across different data centers for redundancy.
    - Overprovision memory capacity to handle increased usage and provide a buffer.

- **Eviction Policy:**
  - When the cache is full, adding new items requires evicting existing ones.
  - **Common Eviction Policies:**
    - **Least Recently Used (LRU):** Removes the least recently accessed items.
    - **Least Frequently Used (LFU):** Removes items accessed least often.
    - **First In First Out (FIFO):** Removes the oldest items in the cache.
  - The choice of eviction policy should align with the application's specific use cases.



### Content delivery network (CDN)

![Figure 9](https://bytebytego.com/images/courses/system-design-interview/scale-from-zero-to-millions-of-users/figure-1-9-SA7OOP7O.svg)



![Figure 10](https://bytebytego.com/_next/image?url=%2Fimages%2Fcourses%2Fsystem-design-interview%2Fscale-from-zero-to-millions-of-users%2Ffigure-1-10-E6HDAMPH.png&w=1200&q=75)



**Content Delivery Network (CDN):**

![Figure 11](https://bytebytego.com/_next/image?url=%2Fimages%2Fcourses%2Fsystem-design-interview%2Fscale-from-zero-to-millions-of-users%2Ffigure-1-11-VI5Z74Q2.png&w=1200&q=75)

- **Definition and Purpose:**
  - A CDN is a network of geographically dispersed servers used to deliver static content efficiently.
  - It caches static assets like images, videos, CSS, and JavaScript files to improve load times and reduce latency for users.

- **How a CDN Works:**
  1. **User Request:**
     - User A requests a static asset (e.g., `image.png`) via a URL provided by the CDN (e.g., `https://mysite.cloudfront.net/logo.jpg`).
  2. **Cache Miss Handling:**
     - If the CDN server closest to the user doesn't have the asset cached, it requests the file from the origin server (web server or storage like Amazon S3).
  3. **Caching the Asset:**
     - The origin server returns the asset along with a Time-to-Live (TTL) header specifying how long it should be cached.
     - The CDN caches the asset and serves it to User A.
  4. **Subsequent Requests:**
     - User B requests the same asset.
     - The CDN serves the cached asset directly if the TTL hasn't expired.

- **Benefits:**
  - **Reduced Latency:**
    - Delivers content from the server closest to the user, speeding up website load times.
  - **Offloading Origin Servers:**
    - Decreases the load on the origin servers by serving cached content.

- **Considerations for Using a CDN:**
  - **Cost:**
    - CDNs are third-party services that charge for data transfers.
    - Caching rarely accessed assets may not be cost-effective.
  - **Cache Expiry Settings:**
    - Set appropriate TTL values to balance content freshness and performance.
    - Too long may serve stale content; too short may increase load on origin servers.
  - **CDN Fallback:**
    - Plan for CDN outages by allowing clients to fetch resources from the origin server if necessary.
  - **Invalidating Cached Files:**
    - **API Invalidation:**
      - Use CDN provider APIs to manually invalidate cached objects before they expire.
    - **Object Versioning:**
      - Add version parameters to asset URLs (e.g., `image.png?v=2`) to force the CDN to retrieve the updated content.

- **Updated System Design with CDN and Cache (Refer to Figure 11):**
  1. **Static Asset Delivery:**
     - Static content (JS, CSS, images) is served via the CDN, not directly from web servers.
     - Enhances performance by reducing latency and server load.
  2. **Reduced Database Load:**
     - Implementing a cache layer diminishes direct database queries.
     - Improves system scalability and response times.



### Stateless web tier



**Stateless Web Tier and Horizontal Scaling:**

- **Moving State Out of Web Servers:**
  - To scale the web tier horizontally, it's essential to decouple user session data from individual web servers.
  - Session data should be stored in persistent storage systems like relational databases or NoSQL databases.
  - This allows any server in the cluster to access the session data, leading to a **stateless web tier**.

- **Stateful vs. Stateless Architecture:**

  - **Stateful Servers:**
    
  - ![Figure 12](https://bytebytego.com/_next/image?url=%2Fimages%2Fcourses%2Fsystem-design-interview%2Fscale-from-zero-to-millions-of-users%2Ffigure-1-12-WTWFBLWX.png&w=1920&q=75)
    - **Definition:** Servers that retain client-specific data (state) between requests.
    - **Operational Challenges:**
      - Clients must consistently connect to the same server to maintain session continuity.
      - Requires load balancers to implement sticky sessions, adding complexity.
      - Scaling is difficult because adding or removing servers disrupts the client-server mapping.
      - Handling server failures is challenging, as session data is tied to specific servers.
  
  - **Stateless Servers:**
    
  - ![Figure 13](https://bytebytego.com/_next/image?url=%2Fimages%2Fcourses%2Fsystem-design-interview%2Fscale-from-zero-to-millions-of-users%2Ffigure-1-13-WILHQ2SA.png&w=1080&q=75)
    - **Definition:** Servers that do not store any client-specific state information.
    - **Advantages:**
      - Any server can handle any request from any client.
      - Simplifies load balancing, as there's no need to track client-server sessions.
      - Easier to scale horizontally by adding or removing servers based on demand.
      - Improves fault tolerance; if a server fails, others can seamlessly take over.
  
- **Implementing a Stateless Architecture:**

- ![Figure 14](https://bytebytego.com/_next/image?url=%2Fimages%2Fcourses%2Fsystem-design-interview%2Fscale-from-zero-to-millions-of-users%2Ffigure-1-14-CCBCQMO6.png&w=1200&q=75)
  - **Shared Data Store:**
    - Session and state data are stored in a shared data store accessible by all web servers.
    - Options include relational databases, NoSQL databases, or in-memory data stores like Memcached/Redis.
    - **NoSQL databases** are often preferred for their scalability.
  
  - **Autoscaling:**
    - With state decoupled from web servers, autoscaling becomes more straightforward.
    - Servers can be automatically added or removed in response to traffic load without affecting user sessions.
  
- **Benefits of a Stateless Web Tier:**

  - **Simpler Architecture:**
    - Reduces complexity in server management and load balancing.
  - **Enhanced Scalability:**
    - Easily accommodates traffic spikes by scaling out web servers.
  - **Improved Reliability:**
    - Mitigates single points of failure; session data isn't lost if a server goes down.
  - **Flexibility:**
    - Facilitates deployment in different environments and supports continuous integration and delivery practices.

- **Preparing for International Growth:**

  - **Need for Multiple Data Centers:**
    - As the user base becomes international, latency and availability become critical concerns.
    - Deploying data centers in multiple geographic locations improves user experience.
  
  - **Advantages of Multi-Data Center Support:**
    - **Reduced Latency:** Servers closer to users result in faster response times.
    - **High Availability:** Regional outages have less impact on the overall service.
    - **Load Distribution:** Traffic is balanced across data centers, preventing overloads.

**Updated System Design (Refer to Figure 14):**

- **Session Data Management:**
  - Session data is moved out of the web tier into a shared, scalable data store.
  - This ensures that all web servers can access and update session information consistently.
  
- **Web Tier Autoscaling:**
  - The stateless nature of the web servers allows for seamless autoscaling.
  - Servers can be dynamically added or removed based on real-time traffic demands.
  
- **Future Considerations:**
  - **Global Expansion:**
    - Plan for deploying infrastructure in multiple regions to support a growing international audience.
  - **Data Consistency Across Regions:**
    - Implement strategies to maintain data consistency and replication across different data centers.
  - **Optimizing User Experience:**
    - Utilize global load balancers to direct users to the nearest data center.
    - Implement CDN and caching strategies tailored for international content delivery.

**Conclusion:**

- Transitioning to a stateless web tier is a crucial step in building a scalable, reliable, and efficient system.
- By decoupling session data from individual servers and leveraging shared data stores, the architecture becomes more adaptable to changing demands.
- Supporting multiple data centers positions the system to provide optimal performance and availability to a global user base.



### Data centers

![Figure 15](https://bytebytego.com/_next/image?url=%2Fimages%2Fcourses%2Fsystem-design-interview%2Fscale-from-zero-to-millions-of-users%2Ffigure-1-15-GICUI26J.png&w=1200&q=75)



**Data Centers and Multi-Data Center Setup:**

- **Multi-Data Center Configuration:**
  - **Purpose:** Enhances availability and user experience by serving content from the data center closest to the user.
  - **GeoDNS Routing:**
    - Users are routed to the nearest data center based on geographic location.
    - Traffic is split between data centers, e.g., **x%** to **US-East** and **(100 – x)%** to **US-West**.
    - GeoDNS resolves domain names to IP addresses according to user location.

- **Handling Data Center Outages:**
  - **Failover Strategy:**
    - In case of a significant outage in one data center, all traffic is redirected to a healthy data center.
    - Ensures continuous service availability even if one location goes offline.

  ![Figure 16](https://bytebytego.com/_next/image?url=%2Fimages%2Fcourses%2Fsystem-design-interview%2Fscale-from-zero-to-millions-of-users%2Ffigure-1-16-DUWJTBCU.png&w=1200&q=75)
  
- **Challenges in Multi-Data Center Setup:**
  - **Traffic Redirection:**
    - Effective tools are needed to direct users to the correct data center.
    - **Solution:** Use GeoDNS to route traffic based on user location.
  - **Data Synchronization:**
    - Users in different regions may interact with different local databases or caches.
    - **Issue:** During failover, data might be unavailable in the alternate data center.
    - **Solution:** Implement data replication across multiple data centers (e.g., asynchronous replication as used by Netflix).
  - **Testing and Deployment:**
    - Critical to test the application across different locations to ensure consistency.
    - **Solution:** Utilize automated deployment tools to maintain consistent services in all data centers.

- **Scaling by Decoupling Components:**
  - **Need for Decoupling:**
    - To scale the system effectively, components should be decoupled to allow independent scaling.
  - **Use of Messaging Queues:**
    - Messaging queues help decouple system components.
    - Enable asynchronous communication and improve system scalability.
    - Widely used in real-world distributed systems to handle load and improve reliability.



### Message queue

![Figure 17](https://bytebytego.com/images/courses/system-design-interview/scale-from-zero-to-millions-of-users/figure-1-17-J2NLNRNY.svg)



**Message Queue:**

- **Definition and Purpose:**
  - A message queue is a durable component, typically stored in memory, that supports asynchronous communication between different parts of a system.
  - Acts as a buffer to distribute asynchronous requests, decoupling producers (publishers) and consumers (subscribers).

- **Basic Architecture:**
  - **Producers/Publishers:**
    - Services that create messages and publish them to the message queue.
  - **Consumers/Subscribers:**
    - Services or servers that connect to the queue and perform actions defined by the messages.
  - **Message Queue:**
    - Serves as the intermediary that stores messages until they are processed by consumers.

- **Benefits of Using Message Queues:**
  - **Decoupling Components:**
    - Producers and consumers operate independently, enhancing scalability and reliability.
    - Producers can post messages even if consumers are unavailable.
    - Consumers can process messages when they are ready, regardless of producer availability.
  - **Asynchronous Processing:**
    - Allows tasks to be performed in the background without blocking the main application flow.
  - **Independent Scaling:**
    - Producers and consumers can be scaled separately based on load.
    - Additional consumers can be added to reduce processing time when the queue is large.

- **Use Case Example: Photo Customization Application:**
  - **Scenario:**
    - An application supports photo customization tasks like cropping, sharpening, and blurring, which are time-consuming.
  - **Implementation:**
    - **Web Servers (Producers):**
      - Publish photo processing jobs to the message queue.
    - **Photo Processing Workers (Consumers):**
      - Retrieve jobs from the queue and perform the customization tasks asynchronously.
  - **Scaling Benefits:**
    - If the message queue grows, more workers can be added to handle the load.
    - If the queue is often empty, the number of workers can be reduced to save resources.

- **Conclusion:**
  - Message queues enable building scalable and reliable applications by decoupling system components.
  - They facilitate asynchronous communication, allowing different parts of the system to operate independently and efficiently.

![Figure 18](https://bytebytego.com/images/courses/system-design-interview/scale-from-zero-to-millions-of-users/figure-1-18-P3WDK5LN.svg)





### Logging, metrics and automation



![Figure 19](https://bytebytego.com/_next/image?url=%2Fimages%2Fcourses%2Fsystem-design-interview%2Fscale-from-zero-to-millions-of-users%2Ffigure-1-19-MOPDW7TD.png&w=1200&q=75)



**Logging, Metrics, and Automation:**

- **Importance in Large Systems:**
  - While optional for small websites, logging, metrics, and automation become essential as a system scales to support a large user base.
  - Investing in these tools helps maintain system performance, reliability, and developer productivity.

- **Logging:**
  - Critical for identifying and diagnosing errors within the system.
  - Can be monitored on individual servers or aggregated into a centralized service for easier searching and analysis.

- **Metrics Collection:**
  - Provides insights into business operations and system health.
  - **Types of Useful Metrics:**
    - **Host-Level Metrics:** CPU usage, memory consumption, disk I/O, etc.
    - **Aggregated Metrics:** Performance metrics for entire tiers like databases and caches.
    - **Business Metrics:** Daily active users, user retention rates, revenue figures, etc.

- **Automation:**
  - Essential for improving productivity in complex systems.
  - **Continuous Integration (CI):**
    - Automates the verification of each code check-in to detect problems early.
  - **Process Automation:**
    - Automating build, test, and deployment processes enhances developer efficiency and reduces errors.

**Updated System Design with Message Queues and Tools (Refer to Figure 19):**

1. **Incorporation of Message Queues:**
   - Adds loose coupling between system components.
   - Improves failure resilience by allowing asynchronous communication.

2. **Integration of Logging, Monitoring, Metrics, and Automation Tools:**
   - Enhances system observability and maintainability.
   - Supports proactive identification of issues and streamlines development workflows.

**Scaling the Data Tier:**

- With continuous data growth, the database may become a bottleneck.
- Scaling the data tier is necessary to handle increasing loads and maintain system performance.



### Database scaling



**Database Scaling**

- **Two Approaches to Database Scaling:**

  - **Vertical Scaling (Scaling Up):**
    - **Definition:** Adding more resources (CPU, RAM, disk space) to an existing database server.
    - **Examples:**
      - Upgrading to powerful servers with high specifications (e.g., 24 TB RAM on Amazon RDS).
      - StackOverflow in 2013 served over 10 million monthly users with a single master database.
    - **Drawbacks:**
      - **Hardware Limits:** There's a maximum capacity for scaling a single machine.
      - **Single Point of Failure:** Relying on one server increases the risk of total system failure if that server crashes.
      - **High Costs:** Upgrading to more powerful hardware is expensive.

  - ![Figure 20](https://bytebytego.com/images/courses/system-design-interview/scale-from-zero-to-millions-of-users/figure-1-20-VLGHMELC.svg)

  - **Horizontal Scaling (Sharding):**
    - **Definition:** Adding more database servers to distribute the load.
    - **Sharding:**
      - Divides a large database into smaller, more manageable pieces called shards.
      - Each shard shares the same schema but contains unique subsets of the data.
      - **Data Distribution:**
        - Uses a sharding key (e.g., `user_id`) and a hash function (e.g., `user_id % 4`) to determine which shard stores a particular piece of data.
    - **Benefits:**
      - **Scalability:** Can handle increased loads by adding more servers.
      - **Performance:** Parallel processing across shards improves query response times.
  - ![Figure 21](https://bytebytego.com/images/courses/system-design-interview/scale-from-zero-to-millions-of-users/figure-1-21-ZDWDWEO5.svg)
  - ![Figure 22](https://bytebytego.com/images/courses/system-design-interview/scale-from-zero-to-millions-of-users/figure-1-22-FI2MHR5M.svg)

- **Key Considerations for Sharding:**
  - **Choosing a Sharding Key:**
    - Must evenly distribute data to prevent any shard from becoming a bottleneck.
    - A good sharding key ensures efficient data retrieval and modification.

  - **Challenges with Sharding:**
    - **Resharding Data:**
      - Necessary when shards become overloaded or data distribution becomes uneven.
      - Involves updating the sharding function and moving data between shards.
      - **Solution:** Use consistent hashing to minimize data movement during resharding.
    - **Celebrity Problem (Hotspot Key Issue):**
      - High-profile entities (e.g., popular celebrities) can create uneven load on specific shards.
      - **Solution:** Allocate dedicated shards for these entities or further partition the data.
    - **Joins and Denormalization:**
      - Joins across shards are complex and inefficient.
      - **Solution:** Denormalize data to minimize the need for cross-shard joins.

- **Integrating NoSQL Databases:**

  - **Purpose:**
    - Offload non-relational data and functionalities to NoSQL databases.
    - Reduce the load on relational databases.
  - **Advantages of NoSQL:**
    - Designed for horizontal scaling.
    - Handle large volumes of unstructured or semi-structured data efficiently.

- **Updated System Design:**

  - **Sharded Databases:**
    - Implement sharding to distribute data across multiple servers.
    - Accommodate rapid data growth and increased traffic.
  - **Use of NoSQL Data Stores:**
    - Move certain functionalities and data types to NoSQL databases.
    - Improve scalability and performance for specific use cases.

**Conclusion:**

- **Scaling the Data Tier:**
  - Both vertical and horizontal scaling have their places, but horizontal scaling is often more sustainable for large-scale systems.
  - Sharding and the use of NoSQL databases are effective strategies for handling big data and high traffic.
- **Considerations:**
  - Careful planning is required to choose appropriate sharding keys and manage the complexities introduced by sharding.
  - Ongoing monitoring and adjustment are necessary to address challenges like resharding and hotspot keys.

![Figure 23](https://bytebytego.com/_next/image?url=%2Fimages%2Fcourses%2Fsystem-design-interview%2Fscale-from-zero-to-millions-of-users%2Ffigure-1-23-3IYFN6Q6.png&w=1200&q=75)

### Millions of users and beyond

Scaling a system is an iterative process. Iterating on what we have learned in this chapter could get us far. More fine-tuning and new strategies are needed to scale beyond millions of users. For example, you might need to optimize your system and decouple the system to even smaller services. All the techniques learned in this chapter should provide a good foundation to tackle new challenges. To conclude this chapter, we provide a summary of how we scale our system to support millions of users:

- Keep web tier stateless
- Build redundancy at every tier
- Cache data as much as you can
- Support multiple data centers
- Host static assets in CDN
- Scale your data tier by sharding
- Split tiers into individual services
- Monitor your system and use automation tools

Congratulations on getting this far! Now give yourself a pat on the back. Good job!



## Back-of-the-envelope Estimation

### Understanding Data Volume Units Using Powers of Two:

- **Fundamental Concepts:**
  
  - A **byte** is a sequence of 8 bits.
  - An ASCII character typically uses one byte of memory.
  - In distributed systems, dealing with large data volumes requires accurate understanding of data units based on powers of two.
  
- **Data Volume Units:**

  | Power | Approximate Value | Full Name | Abbreviation |
  | ----- | ----------------- | --------- | ------------ |
  | 2¹⁰   | 1 Thousand        | Kilobyte  | KB           |
  | 2²⁰   | 1 Million         | Megabyte  | MB           |
  | 2³⁰   | 1 Billion         | Gigabyte  | GB           |
  | 2⁴⁰   | 1 Trillion        | Terabyte  | TB           |
  | 2⁵⁰   | 1 Quadrillion     | Petabyte  | PB           |

- **Importance in Calculations:**
  - Knowing these units is crucial for performing correct calculations in distributed systems.
  - Helps in estimating storage requirements, data transfer sizes, and system capacities accurately.



### Latency numbers

**Latency Numbers Every Programmer Should Know**

Understanding the relative speeds of various computer operations is crucial for optimizing system performance. While hardware advancements have improved absolute speeds since 2010, the relative differences remain significant and informative for system design.

- **Typical Operation Latencies:**

  | **Operation**                         | **Time**                |
  | ------------------------------------- | ----------------------- |
  | L1 cache reference                    | 0.5 ns                  |
  | Branch mispredict                     | 5 ns                    |
  | L2 cache reference                    | 7 ns                    |
  | Mutex lock/unlock                     | 100 ns                  |
  | Main memory reference                 | 100 ns                  |
  | Compress 1 KB with Zippy              | 10,000 ns (10 µs)       |
  | Send 2 KB over 1 Gbps network         | 20,000 ns (20 µs)       |
  | Read 1 MB sequentially from memory    | 250,000 ns (250 µs)     |
  | Round trip within the same datacenter | 500,000 ns (500 µs)     |
  | Disk seek                             | 10,000,000 ns (10 ms)   |
  | Read 1 MB sequentially from network   | 10,000,000 ns (10 ms)   |
  | Read 1 MB sequentially from disk      | 30,000,000 ns (30 ms)   |
  | Send packet CA → Netherlands → CA     | 150,000,000 ns (150 ms) |

- **Time Unit Conversions:**

  - **Nanosecond (ns):** 1 ns = 10⁻⁹ seconds
  - **Microsecond (µs):** 1 µs = 10⁻⁶ seconds = 1,000 ns
  - **Millisecond (ms):** 1 ms = 10⁻³ seconds = 1,000 µs = 1,000,000 ns

**Key Takeaways:**

- **Memory vs. Disk Speed:**
  - Accessing data from memory (cache or main memory) is extremely fast compared to disk operations.
  - Disk seeks are slow; minimizing disk access can significantly improve performance.

- **Importance of Caching:**
  - Utilizing caches (L1, L2) can greatly reduce access times for frequently used data.
  - Designing systems to maximize cache hits can enhance overall efficiency.

- **Compression Efficiency:**
  - Simple compression algorithms are fast and can reduce the amount of data transmitted.
  - Compressing data before network transmission can save time despite the compression overhead.

- **Network Latency:**
  - Data transfer times increase with physical distance, especially across continents.
  - Round-trip times within the same datacenter are relatively low but still significant compared to in-memory operations.

- **Optimizing Data Transfer:**
  - Sending data over high-speed networks is faster than reading from disk but slower than memory operations.
  - Strategies like data compression and minimizing data size can improve network transfer efficiency.

**Practical Implications:**

- **Design for In-Memory Operations:**
  - Keep critical data in memory when possible to reduce latency.
  - Use in-memory databases or caching layers for frequently accessed data.

- **Minimize Disk Access:**
  - Avoid unnecessary disk reads/writes by optimizing data storage and retrieval patterns.
  - Employ solid-state drives (SSDs) to reduce disk access times where disk usage is unavoidable.

- **Efficient Networking:**
  - Optimize network communication by reducing data size and frequency of requests.
  - Place servers and services geographically closer to users to reduce latency.

- **Use Compression Wisely:**
  - Apply compression to large data transfers to save time and bandwidth.
  - Balance the computational cost of compression against network transfer times.

**Conclusion:**

- **Awareness of Latency Hierarchies:**
  - Programmers should be mindful of the vast differences in operation speeds when designing systems.
  - Optimizing code and architecture based on these latency considerations can lead to significant performance gains.

- **Strategic Optimization:**
  - Focus on areas where latency is highest (e.g., disk access, long-distance network communication) for optimization efforts.
  - Utilize asynchronous operations and parallel processing to mitigate the impact of slower operations.

By understanding and applying these latency insights, developers can create more efficient, responsive, and scalable systems.





### Availability numbers

**Availability Numbers and Their Significance**

- **High Availability Definition:**
  - High availability refers to a system's ability to remain operational without interruption for a desired period.
  - It is quantified as a percentage, with 100% indicating zero downtime.
  - Most services aim for availability between 99% and 100%.

- **Service Level Agreement (SLA):**
  - An SLA is a formal agreement between a service provider and a customer, defining the expected level of service uptime.
  - Major cloud providers like Amazon, Google, and Microsoft typically offer SLAs of 99.9% or higher.

- **Uptime Measured in "Nines":**
  - Availability is often expressed in terms of "nines" to represent the percentage of uptime.
    - **Two Nines:** 99%
    - **Three Nines:** 99.9%
    - **Four Nines:** 99.99%
    - **Five Nines:** 99.999%
    - **Six Nines:** 99.9999%
  - The more nines, the higher the availability and the lower the permissible downtime.

- **Downtime Corresponding to Availability Percentages:**

  The following table illustrates the maximum allowable downtime for different availability levels:

  | **Availability (%)** | **Downtime per Day** | **Downtime per Week** | **Downtime per Month** | **Downtime per Year** |
  | -------------------- | -------------------- | --------------------- | ---------------------- | --------------------- |
  | 99%                  | 14.4 minutes         | 1.68 hours            | 7.31 hours             | 3.65 days             |
  | 99.9%                | 1.44 minutes         | 10.1 minutes          | 43.8 minutes           | 8.76 hours            |
  | 99.99%               | 8.64 seconds         | 1.01 minutes          | 4.38 minutes           | 52.6 minutes          |
  | 99.999%              | 864 milliseconds     | 6.05 seconds          | 26.3 seconds           | 5.26 minutes          |
  | 99.9999%             | 86.4 milliseconds    | 604.8 milliseconds    | 2.63 seconds           | 31.5 seconds          |

- **Understanding the Calculations:**

  - **Time Units:**
    - 1 second (s) = 1,000 milliseconds (ms)
    - 1 minute = 60 seconds
    - 1 hour = 60 minutes
    - 1 day = 24 hours

  - **Calculating Downtime:**

    - **Per Day (Based on 86,400 seconds in a day):**
      - **99% Availability:**
        - Downtime = 1% of 86,400 seconds = 864 seconds = 14.4 minutes
      - **99.999% Availability:**
        - Downtime = 0.001% of 86,400 seconds = 0.864 seconds = 864 milliseconds

    - **Per Week (Based on 604,800 seconds in a week):**
      - **99% Availability:**
        - Downtime = 1% of 604,800 seconds = 6,048 seconds = 1.68 hours
      - **99.999% Availability:**
        - Downtime = 0.001% of 604,800 seconds = 6.048 seconds

    - **Per Month (Assuming 730 hours in a month):**
      - **99% Availability:**
        - Downtime = 1% of 730 hours = 7.3 hours
      - **99.999% Availability:**
        - Downtime = 0.001% of 730 hours = 0.00438 hours ≈ 15.8 seconds

    - **Per Year (Based on 31,536,000 seconds in a year):**
      - **99% Availability:**
        - Downtime = 1% of 31,536,000 seconds = 315,360 seconds = 87.6 hours ≈ 3.65 days
      - **99.999% Availability:**
        - Downtime = 0.001% of 31,536,000 seconds = 315.36 seconds ≈ 5.26 minutes

- **Key Takeaways:**

  - **Higher Availability Requires More Robust Systems:**
    - Achieving additional "nines" of availability often requires significant investment in redundancy, failover mechanisms, and infrastructure.
  - **Impact of Downtime:**
    - Even small percentages of downtime can translate to significant periods, affecting user experience and service reliability.
  - **SLA Commitments:**
    - Service providers must design their systems to meet or exceed their SLA commitments to avoid penalties and maintain customer trust.

- **Conclusion:**

  - Understanding availability percentages and their real-world implications is crucial for designing systems that meet desired reliability standards.
  - Organizations must balance the costs and complexity of achieving higher availability against the potential impact of downtime on their services.



**Summary: Estimating Twitter's QPS and Storage Requirements**

**Assumptions:**

- **Monthly Active Users (MAU):** 300 million
- **Daily Active Users (DAU):** 50% of MAU
- **Average Tweets per User per Day:** 2
- **Percentage of Tweets with Media:** 10%
- **Data Retention Period:** 5 years

---

**Calculations:**

1. **Daily Active Users (DAU):**

   $
   \text{DAU} = 300\, \text{million} \times 50\% = \mathbf{150\, \text{million users}}
   $

2. **Total Tweets per Day:**

   $
   \text{Total Tweets} = 150\, \text{million users} \times 2\, \text{tweets/user} = \mathbf{300\, \text{million tweets/day}}
   $

3. **Tweets per Second (QPS):**

   - **Total Seconds in a Day:**

     $
     24\, \text{hours} \times 3600\, \text{seconds/hour} = 86,400\, \text{seconds}
     $

   - **Average QPS:**

     $
     \text{QPS} = \frac{300\, \text{million tweets/day}}{86,400\, \text{seconds/day}} \approx \mathbf{3472\, \text{QPS}}
     $

     Rounded to approximately **3500 QPS**.

   - **Peak QPS:**

     $
     \text{Peak QPS} = 2 \times 3500\, \text{QPS} = \mathbf{7000\, \text{QPS}}
     $

4. **Media Storage Estimation:**

   - **Average Tweet Components Size:**

     - `tweet_id`: 64 bytes
     - `text`: 140 bytes
     - `media`: 1 MB (only for tweets with media)

   - **Total Media Tweets per Day:**

     $
     \text{Media Tweets} = 300\, \text{million tweets/day} \times 10\% = \mathbf{30\, \text{million media tweets/day}}
     $

   - **Daily Media Storage Requirement:**

     $
     \text{Daily Media Storage} = 30\, \text{million} \times 1\, \text{MB} = \mathbf{30\, \text{TB/day}}
     $

     (Since $\(1\, \text{MB} \times 1\, \text{million} = 1\, \text{TB}\))$

   - **5-Year Media Storage Requirement:**

     $
     \text{Total Storage} = 30\, \text{TB/day} \times 365\, \text{days/year} \times 5\, \text{years} = 54,750\, \text{TB} \approx \mathbf{55\, \text{PB}}
     $

     (Since \(1\, \text{PB} = 1,000\, \text{TB}\))

---

**Summary of Estimates:**

- **Average Tweets per Second (QPS):** Approximately **3500 QPS**
- **Peak Tweets per Second (QPS):** Approximately **7000 QPS**
- **Daily Media Storage Needed:** **30 TB**
- **Total Media Storage Over 5 Years:** Approximately **55 PB**

**Notes:**

- These calculations focus on media storage requirements and do not account for additional storage needed for text-only tweets or metadata beyond the specified components.
- The estimates are based on the provided assumptions and are intended for illustrative purposes.



### **Tips for Back-of-the-Envelope Estimation**

Back-of-the-envelope estimation focuses on demonstrating your problem-solving process rather than obtaining exact results. Interviewers often assess your analytical approach. Here are some tips to help you:

- **Use Rounding and Approximation:**
  - Simplify complex calculations by rounding numbers to make mental math easier.
  - **Example:**
    - Instead of calculating \(99987 \div 9.1\), approximate it as \(100,000 \div 10\).
  - Precision is not expected; it's more important to reach a reasonable estimate efficiently.

- **Write Down Your Assumptions:**
  - Clearly state any assumptions you make during your estimation.
  - This provides a reference point and helps others understand your reasoning.
  - **Example:**
    - Assume an average user sends 50 messages per day.

- **Label Your Units:**
  - Always include units with your numbers to avoid confusion.
  - **Example:**
    - Write "5 MB" instead of just "5" to specify the data size.
  - Units help ensure clarity and accuracy in your calculations.

- **Practice Common Estimations:**
  - Familiarize yourself with estimating:
    - Queries Per Second (QPS) and peak QPS
    - Storage requirements
    - Cache sizes
    - Number of servers needed
  - **Tip:**
    - Regular practice enhances your ability to perform quick estimations during interviews.

- **Focus on the Process:**
  - Demonstrate logical thinking and a structured approach.
  - Break down complex problems into smaller, manageable parts.

Remember, the goal is to showcase your analytical skills and how you approach solving problems under constraints.



## Distributed Message Queue



# Designing a Distributed Message Queue

In modern system architecture, components are often broken down into small, independent building blocks with well-defined interfaces. **Message queues** play a crucial role by providing communication and coordination between these components. They offer several benefits:

- **Decoupling**: Eliminates tight coupling between components, allowing them to be updated independently.
- **Improved Scalability**: Producers and consumers can be scaled independently based on traffic load. For example, more consumers can be added during peak hours to handle increased traffic.
- **Increased Availability**: If one part of the system goes offline, other components can continue to interact with the queue.
- **Better Performance**: Facilitates asynchronous communication, enabling producers to add messages without waiting for responses and consumers to process messages when available.

**Figure 1: Popular Distributed Message Queues**

![Figure 1 Popular distributed message queues](https://bytebytego.com/_next/image?url=%2Fimages%2Fcourses%2Fsystem-design-interview%2Fdistributed-message-queue%2Ffigure-1-popular-distributed-message-queues-NHCVSN5F.png&w=1200&q=75)

### Message Queues vs. Event Streaming Platforms

While platforms like **Apache Kafka** and **Pulsar** are primarily event streaming platforms, the distinction between them and traditional message queues (e.g., RocketMQ, ActiveMQ, RabbitMQ, ZeroMQ) is becoming less clear due to overlapping features:

- **RabbitMQ**, a typical message queue, has added streaming features like repeated message consumption and long message retention using an append-only log.
- **Apache Pulsar** competes with Kafka but is flexible and performant enough to function as a distributed message queue.

## Design Focus

In this chapter, we will design a distributed message queue that includes additional features typically found in event streaming platforms:

- **Long Data Retention**: Ability to store messages for extended periods.
- **Repeated Consumption of Messages**: Consumers can read the same message multiple times.

These features introduce complexity to the design. Throughout the chapter, we will highlight areas where simplifications can be made if the focus is on traditional message queue functionalities.



# Step 1: Understand the Problem and Establish Design Scope

The basic functionality of a **message queue** involves producers sending messages to the queue and consumers retrieving them. However, designing a distributed message queue requires consideration of additional factors like performance, message delivery semantics, data retention, and more. The following summarizes the key points from a clarifying conversation between a candidate and an interviewer.

## Clarifying Questions and Answers

1. **Message Format and Size:**
   - **Question:** What's the format and average size of messages? Is it text only? Is multimedia allowed?
   - **Answer:** Text messages only, generally measured in kilobytes (KB).

2. **Message Consumption:**
   - **Question:** Can messages be repeatedly consumed?
   - **Answer:** Yes, messages can be repeatedly consumed by different consumers. This is an added feature beyond traditional message queues.

3. **Message Ordering:**
   - **Question:** Are messages consumed in the same order they were produced?
   - **Answer:** Yes, messages should be consumed in the same order they were produced. This is an added feature not typically guaranteed by traditional message queues.

4. **Data Persistence and Retention:**
   - **Question:** Does data need to be persisted, and what is the data retention period?
   - **Answer:** Yes, data should be persisted with a retention period of two weeks. This feature extends beyond the capabilities of traditional message queues.

5. **Number of Producers and Consumers:**
   - **Question:** How many producers and consumers are we going to support?
   - **Answer:** The system should support as many as possible.

6. **Data Delivery Semantics:**
   - **Question:** What data delivery semantics need to be supported (e.g., at-most-once, at-least-once, exactly-once)?
   - **Answer:** At a minimum, support for **at-least-once** delivery is required. Ideally, the system should support all semantics and make them configurable.

7. **Throughput and Latency Requirements:**
   - **Question:** What's the target throughput and end-to-end latency?
   - **Answer:** The system should support high throughput for use cases like log aggregation and low latency for traditional message queue use cases.

## Functional Requirements

Based on the conversation, the following functional requirements are established:

- **Message Production and Consumption:**
  - Producers can send messages to the message queue.
  - Consumers can consume messages from the message queue.

- **Message Retention and Re-consumption:**
  - Messages can be consumed multiple times or only once, depending on configuration.
  - Historical data can be truncated after the retention period.

- **Message Characteristics:**
  - Message size is in the kilobyte range.
  - Messages are delivered to consumers in the order they were added to the queue.

- **Data Delivery Semantics:**
  - Support configurable delivery semantics: at-least-once, at-most-once, and exactly-once.

## Non-Functional Requirements

- **Performance:**
  - High throughput and low latency, configurable based on use cases.

- **Scalability:**
  - The system should be distributed and capable of handling sudden surges in message volume.

- **Durability and Persistence:**
  - Data must be persisted to disk and replicated across multiple nodes to prevent data loss.

## Adjustments for Traditional Message Queues

- **Retention Requirements:**
  - Traditional message queues like RabbitMQ do not retain messages long-term; they keep messages only until they are consumed.
  - On-disk overflow capacities are smaller compared to event streaming platforms.

- **Message Ordering:**
  - Traditional message queues do not typically guarantee that messages are consumed in the same order they were produced.
  - These differences can simplify the design if such features are not required.

**Note:** Throughout the design process, we will highlight areas where the design could be simplified if focusing on traditional message queue functionalities.





# Step 2: Propose High-Level Design and Get Buy-In

First, let's discuss the basic functionalities of a **message queue**.

**Figure 2: Key Components in a Message Queue**

![Figure 2 Key components in a message queue](https://bytebytego.com/images/courses/system-design-interview/distributed-message-queue/figure-2-key-components-in-a-message-queue-EVGQ4EYZ.svg)

## Key Components and Interactions

- **Producer**:
  - Sends messages to the message queue.
- **Consumer**:
  - Subscribes to the queue and consumes the messages.
- **Message Queue**:
  - Acts as an intermediary service that decouples producers and consumers.
  - Allows producers and consumers to operate and scale independently.

Both the producer and consumer are clients in the client-server model, with the message queue serving as the server. Communication between clients and the server occurs over the network.

# Messaging Models

The most popular messaging models are **point-to-point** and **publish-subscribe**.

## Point-to-Point Model

- **Description:**
  - In this model, a message is sent to a queue and consumed by one and only one consumer.
  - Multiple consumers may be waiting to consume messages from the queue, but each message is delivered to a single consumer only.
- **Behavior:**
  - Once a consumer acknowledges receipt of a message, the message is removed from the queue.
  - There is no data retention; messages are not stored after consumption.
- **Illustration:**
  - ![Figure 3 Point-to-point model](https://bytebytego.com/images/courses/system-design-interview/distributed-message-queue/figure-3-point-to-point-model-RKDLREMI.svg)
    - Message A is consumed only by Consumer 1.

- **Limitations in Our Design:**
  - Our design includes a persistence layer that retains messages for two weeks, allowing messages to be consumed multiple times.
  - While we can simulate a point-to-point model, our design naturally aligns more with the publish-subscribe model.

## Publish-Subscribe Model

### Introduction of Topics

- **Topic:**
  - A category used to organize messages.
  - Each topic has a unique name within the message queue service.
  - Messages are sent to and read from a specific topic.

### Behavior

- **Publish-Subscribe Model:**
  - A message sent to a topic is received by all consumers subscribing to that topic.
  - Consumers can independently consume messages without affecting each other.

- **Illustration:**
  - ![Figure 4 Publish-subscribe model](https://bytebytego.com/images/courses/system-design-interview/distributed-message-queue/figure-4-publish-subscribe-model-HKA6TRGS.svg)
    - Message A is consumed by both Consumer 1 and Consumer 2.

## Supporting Both Models

- **Our Distributed Message Queue:**
  - Supports both point-to-point and publish-subscribe models.
  - **Publish-Subscribe Implementation:**
    - Achieved through the use of topics.
  - **Point-to-Point Simulation:**
    - Implemented using the concept of **consumer groups** (to be introduced in a later section).
    - Within a consumer group, each message is consumed by only one consumer, effectively simulating the point-to-point behavior.



# Topics, Partitions, and Brokers

In designing a distributed message queue, handling large volumes of data for a single topic requires effective scaling strategies. One such approach is using **partitions**.

## Partitioning (Sharding)

- **Purpose**: To distribute the load of a topic that is too large for a single server to handle.
- **Method**:
  - **Divide a Topic into Partitions**: Each partition is a subset of the messages for that topic.
  - **Distribute Partitions Across Brokers**: Partitions are evenly distributed across servers in the message queue cluster.
  - **Scalability**: Increase the number of partitions to scale the topic's capacity.

**Figure 5: Partitions**

![Figure 5 Partitions](https://bytebytego.com/images/courses/system-design-interview/distributed-message-queue/figure-5-partitions-53G6JYSP.svg)

## Brokers

- **Definition**: Servers that hold partitions.
- **Role**:
  - Manage the storage and retrieval of messages within their assigned partitions.
  - Facilitate high scalability by distributing partitions among multiple brokers.

## Message Ordering and Offsets

- **FIFO Mechanism**: Each topic partition operates as a queue with First-In-First-Out ordering.
- **Offset**:
  - The position of a message within a partition.
  - Used to keep track of which messages have been consumed.

## Producers and Message Keys

- **Message Sending**:
  - Producers send messages to a specific partition within a topic.
  - Messages can include an optional **message key** (e.g., a user's ID).
- **Partition Assignment**:
  - Messages with the same key are sent to the same partition, ensuring order for that key.
  - If no key is provided, messages are distributed randomly across partitions.

## Consumers and Consumer Groups

- **Consuming Messages**:
  - Consumers subscribe to a topic and pull data from one or more partitions.
- **Consumer Groups**:
  - When multiple consumers subscribe to the same topic, they can form a consumer group.
  - Each consumer in the group is responsible for a subset of the partitions.
  - This ensures that each message is processed by only one consumer within the group.

## Message Queue Cluster

**Figure 6: Message Queue Cluster**

![Figure 6 Message queue cluster](https://bytebytego.com/images/courses/system-design-interview/distributed-message-queue/figure-6-message-queue-cluster-B3TAY3V2.svg)

- **Components**:
  - **Brokers**: Servers managing partitions.
  - **Partitions**: Segments of a topic distributed across brokers.
- **Functionality**:
  - Distributes the messaging workload for scalability and reliability.
  - Allows the system to handle large volumes of messages efficiently.

## Summary

- **Partitioning** enables a topic to handle large data volumes by dividing it into manageable pieces.
- **Brokers** store these partitions and facilitate message storage and retrieval.
- **Producers** can include a message key to ensure messages with the same key are ordered within a partition.
- **Consumers** pull messages from partitions, and consumer groups help distribute the load among multiple consumers.
- This architecture enhances scalability, maintains message order within partitions, and allows for efficient handling of high-throughput messaging systems.



# Consumer Groups

To support both **point-to-point** and **publish-subscribe** models, we introduce the concept of **consumer groups**. A consumer group is a set of consumers working together to consume messages from topics.

- **Organization of Consumers:**
  - Consumers can be grouped based on use cases or functionalities.
    - **Example:**
      - **Consumer Group 1** subscribes to **Topic A**.
      - **Consumer Group 2** subscribes to both **Topic A** and **Topic B**.
  - Each consumer group maintains its own consuming offsets for the topics it subscribes to.

- **Parallel Consumption:**
  - Instances within the same consumer group can consume traffic in parallel.
  - If multiple consumer groups subscribe to the same topic, the same message is consumed by multiple consumers, supporting the **publish-subscribe** model.

**Figure 7: Consumer Groups**

![Figure 7 Consumer groups](https://bytebytego.com/images/courses/system-design-interview/distributed-message-queue/figure-7-consumer-groups-BBTZB7CF.svg)

## Challenge with Message Ordering

- **Issue:**
  - Reading data in parallel improves throughput but may compromise the consumption order of messages within the same partition.
  - If multiple consumers in the same group read from the same partition, the order of message consumption cannot be guaranteed.
    - **Example:**
      - If **Consumer 1** and **Consumer 2** both read from **Partition 1**, message order may not be preserved.

## Solution: Partition Consumption Constraint

- **Constraint:**
  - **A single partition can only be consumed by one consumer within the same consumer group.**
  - This ensures that message order within a partition is maintained.

- **Implications:**
  - If the number of consumers in a group exceeds the number of partitions for a topic, some consumers will not receive data from that topic.
    - **Example:**
      - In **Figure 7**, **Consumer 3** in **Group 2** cannot consume messages from **Topic B** because **Consumer 4** is already consuming from that partition within the same group.

- **Benefits:**
  - Enforcing this constraint maintains the message order and effectively simulates the **point-to-point** model within a consumer group.
  - By ensuring each partition is consumed by only one consumer in the group, we preserve the FIFO (First-In-First-Out) order of messages.

## Scaling Considerations

- **Partitions as the Smallest Unit:**
  - A partition is the smallest unit of storage and consumption.
  - Allocating enough partitions in advance avoids the need to dynamically increase partitions later.
  
- **Handling High Scale:**
  - To scale, we can add more consumers to the consumer group.
  - Ensure the number of partitions is equal to or greater than the number of consumers in the group to utilize all consumers effectively.
  - This approach allows for high throughput while maintaining message order within partitions.

---

By using consumer groups and applying the constraint that each partition is consumed by only one consumer within the same group, we can support both messaging models and ensure message order, scalability, and efficient resource utilization.



# High-Level Architecture of the Distributed Message Queue

The updated high-level design includes several key components that manage the interaction between clients, core services, storage, and coordination services.

## **Clients**

1. **Producer**:
   - Pushes messages to specific topics.
   
2. **Consumer Group**:
   - Subscribes to topics and consumes messages, with consumers organized into groups for parallel consumption.

## **Core Service and Storage**

1. **Broker**:
   - Holds multiple partitions. Each partition stores a subset of the messages for a topic.
   
2. **Storage**:
   - **Data Storage**: Messages are persisted within partitions for a specific topic.
   - **State Storage**: Manages the consumer states, such as offsets, to track message consumption progress.
   - **Metadata Storage**: Persists configuration and properties related to topics, such as partition configurations.

## **Coordination Service**

1. **Service Discovery**:
   - Keeps track of which brokers are alive and available for message handling.

2. **Leader Election**:
   - Selects a single broker as the **active controller** in the cluster.
   - The active controller is responsible for assigning partitions and managing the overall system.
   
   - **Common Tools**: 
     - **Apache Zookeeper** or **etcd** are often used to handle leader election and manage service coordination.

---

This architecture ensures a scalable, fault-tolerant system where producers and consumers can interact with partitions managed by brokers, and coordination services ensure smooth operation through leader election and service discovery.



# High-Level Architecture of the Distributed Message Queue

The updated high-level design includes several key components that manage the interaction between clients, core services, storage, and coordination services.

![Figure 8 High-level design](https://bytebytego.com/images/courses/system-design-interview/distributed-message-queue/figure-8-high-level-design-5GF6PDU2.svg)

## **Clients**

1. **Producer**:
   - Pushes messages to specific topics.
   
2. **Consumer Group**:
   - Subscribes to topics and consumes messages, with consumers organized into groups for parallel consumption.

## **Core Service and Storage**

1. **Broker**:
   - Holds multiple partitions. Each partition stores a subset of the messages for a topic.
   
2. **Storage**:
   - **Data Storage**: Messages are persisted within partitions for a specific topic.
   - **State Storage**: Manages the consumer states, such as offsets, to track message consumption progress.
   - **Metadata Storage**: Persists configuration and properties related to topics, such as partition configurations.

## **Coordination Service**

1. **Service Discovery**:
   - Keeps track of which brokers are alive and available for message handling.

2. **Leader Election**:
   - Selects a single broker as the **active controller** in the cluster.
   - The active controller is responsible for assigning partitions and managing the overall system.
   
   - **Common Tools**: 
     - **Apache Zookeeper** or **etcd** are often used to handle leader election and manage service coordination.

---

This architecture ensures a scalable, fault-tolerant system where producers and consumers can interact with partitions managed by brokers, and coordination services ensure smooth operation through leader election and service discovery.



# Step 3 - Design Deep Dive

To achieve **high throughput** while maintaining **high data retention**, we made three critical design choices:

1. **On-disk data structure**: We leverage the excellent sequential access performance of rotational disks and the aggressive disk caching strategies of modern operating systems.
  
2. **Minimal message modification**: The message data structure allows messages to move from the producer to the queue and finally to the consumer without modifications, minimizing expensive copying operations.

3. **Batching**: To enhance throughput, we designed the system to favor batching. Producers send messages in batches, the queue persists them in larger batches, and consumers fetch them in batches whenever possible.

---

## Data Storage Options

When persisting messages, we must account for the write-heavy nature of a message queue, predominantly sequential read/write access, and no need for updates or deletes (except when truncating old data). Let's evaluate two potential storage options:

### **Option 1: Database**

- **Relational Database**: Use tables to store messages as rows.
- **NoSQL Database**: Use collections to store messages as documents.
  

**Problem**: Databases are not ideal for our use case due to challenges in balancing write-heavy and read-heavy patterns at scale. They could become a **bottleneck**.

### **Option 2: Write-Ahead Log (WAL)**

- **WAL**: A simple append-only log where new entries are appended to the end. This structure is commonly used in systems like MySQL and ZooKeeper.
- **Sequential Access**: WAL offers pure sequential read/write access, and modern rotational disks are optimized for this type of workload.

We recommend using **WAL** for persisting messages due to its excellent sequential access performance and affordability, especially when combined with RAID for increased performance.

---

## Append-Only Log and Segmenting

![Figure 9 Append new messages](https://bytebytego.com/images/courses/system-design-interview/distributed-message-queue/figure-9-append-new-messages-7IQA6BDN.svg)

- **Message Append**: New messages are appended to the **tail** of a partition, each with an increasing offset (e.g., line number in the log).
- **Segmenting**: To manage the file size, the log is divided into **segments**. New messages are written to the active segment. When the segment reaches its size limit, a new active segment is created, and the old one becomes inactive.
  
  - Inactive segments only serve read requests.
  - Old inactive segments are **truncated** when they exceed the retention period or capacity limit.

![Figure 10 Data segment file distribution in topic partitions](https://bytebytego.com/images/courses/system-design-interview/distributed-message-queue/figure-10-data-segment-file-distribution-in-topic-partitions-TZBXX5CG.svg)

- **Directory Structure**: Segment files for a partition are organized in folders, e.g., `"Partition-{:partition_id}"`.

---

## Disk Performance Considerations

- **Rotational Disks**: While rotational disks are slow for random access, they perform well with **sequential access**. Modern RAID-configured disks can achieve several hundred MB/sec of read/write speed, which is sufficient for high-throughput systems.
  
- **OS Disk Caching**: Modern operating systems aggressively cache disk data in memory, making it possible to benefit from faster access even with disk-based storage.

---

## Summary

Our design choices, including the use of **WAL** for sequential read/write access, batching, and minimal message modifications, allow us to meet the demands of high-throughput and high-retention message queue systems. By leveraging modern disk caching strategies and RAID configurations, we optimize both performance and cost-efficiency.



# Message Data Structure

The message data structure is critical for achieving high throughput in a distributed message queue system. By defining a consistent contract between **producers**, the **message queue**, and **consumers**, our design minimizes the need for expensive data copying, improving performance. Any discrepancies in the message structure would require mutation, which could degrade system efficiency.

### **Sample Message Data Schema**

| **Field Name** | **Data Type** |
| -------------- | ------------- |
| key            | byte[]        |
| value          | byte[]        |
| topic          | string        |
| partition      | integer       |
| offset         | long          |
| timestamp      | long          |
| size           | integer       |
| crc            | integer       |

**Table 1: Data schema of a message**

---

## **Field Explanations**

### **Message Key**

- **Purpose**: Determines the partition to which a message is assigned.
- **Behavior**:
  - If the key is undefined, a partition is chosen randomly.
  - If defined, the partition is determined by `hash(key) % numPartitions`.
- **Flexibility**: Producers can implement custom mapping algorithms to assign partitions.
- **Usage**: The key can be a string or a number and typically contains business-related information. However, keys are **not required to be unique**.
- **Note**: The key is distinct from the partition number, which is a concept internal to the message queue and not exposed to clients.

### **Message Value**

- **Purpose**: This is the actual **payload** of the message, which could be plain text or a compressed binary block.
- **Distinction**: The message's key and value differ from a key-value store. In a message queue, the key does not need to be unique, and keys may not always be mandatory.

### **Other Fields**

- **Topic**: The name of the topic to which the message belongs.
- **Partition**: The ID of the partition the message is assigned to.
- **Offset**: The position of the message in the partition, uniquely identifying the message when combined with the **topic** and **partition**.
- **Timestamp**: The time when the message was stored.
- **Size**: The size of the message in bytes.
- **CRC (Cyclic Redundancy Check)**: Used to verify the **integrity** of the message data.

---

## **Additional Fields and Features**

- Optional fields, like **tags**, can be added to support advanced features such as message filtering.
  

By maintaining a well-defined message data structure, we ensure consistency across the system, minimizing performance overheads and supporting features like partitioning, high throughput, and data integrity.



# Batching in Message Queue Design

**Batching** is a key component of this message queue design, significantly improving performance across the producer, consumer, and message queue itself. In this section, we focus on batching within the message queue.

## Why Batching is Important:

1. **Network Efficiency**:
   - Batching allows the operating system to group multiple messages into a single network request.
   - This amortizes the cost of expensive network round trips, making message delivery more efficient.

2. **Improved Disk Performance**:
   - Brokers write messages in large chunks to append logs, leading to:
     - Larger **blocks of sequential writes**.
     - Larger **contiguous disk cache** blocks managed by the OS.
   - These optimizations maximize **sequential disk access throughput**, improving performance.

## Throughput vs. Latency Tradeoff:

- **Latency Focus**:
  - If the system is configured like a traditional message queue where latency is critical, smaller batch sizes should be used.
  - **Drawback**: This reduces disk performance slightly but prioritizes quicker message delivery.

- **Throughput Focus**:
  - When throughput is the priority, larger batch sizes should be used.
  - To counterbalance the slower sequential disk writes, **more partitions per topic** might be needed.

## Next Steps:

Now that we've covered the message queue's disk storage subsystem and batching, we will dive into the **producer** and **consumer** flows before completing the deep dive into the message queue system. This will give a comprehensive understanding of how batching, disk optimization, and message flow work together to optimize performance.





# Producer Flow

When a producer sends messages to a partition, it must decide which broker to connect to. One initial approach is to use a **routing layer** to handle this decision.

## **Option 1: Using a Routing Layer**

![Figure 11 Routing layer](https://bytebytego.com/images/courses/system-design-interview/distributed-message-queue/figure-11-routing-layer-LA4CPIQY.svg)

- **Flow**:
  1. The producer sends messages to the **routing layer**.
  2. The routing layer reads the **replica distribution** from metadata storage and caches it.
  3. The routing layer forwards the message to the **leader replica** of the correct partition (e.g., partition 1 of topic A, stored in **broker 1**).
  4. **Follower replicas** pull data from the leader.
  5. Once "enough" replicas have synchronized the message, the leader **commits** the data (persisted on disk), and the producer receives an acknowledgment.

- **Reason for Leader and Follower Replicas**:
  - Fault tolerance: By replicating data across multiple brokers, the system ensures resilience in case of broker failures.

### **Drawbacks** of the Routing Layer:

- **Increased Latency**: Introducing a routing layer adds extra network hops and overhead, leading to higher latency.
- **Batching Inefficiency**: The design doesn't prioritize batching, reducing overall efficiency.

---

## **Option 2: Improved Design with Integrated Buffer and Routing**

![Figure 12 Producer with buffer and routing](https://bytebytego.com/images/courses/system-design-interview/distributed-message-queue/figure-12-producer-with-buffer-and-routing-TEGPFRV4.svg)

To improve efficiency, the routing logic and a **buffer** component are integrated into the **producer** itself, as part of the producer's client library.

- **Benefits**:
  1. **Reduced Network Hops**: With the routing layer integrated into the producer, fewer network hops reduce latency.
  2. **Custom Partition Logic**: Producers can apply their own logic to determine which partition to send the message to, increasing flexibility.
  3. **Batching**: Messages are buffered in memory, allowing producers to send larger batches in a single request, increasing throughput.

---

## **Batch Size Tradeoff**

![Figure 13 The choice of the batch size](https://bytebytego.com/images/courses/system-design-interview/distributed-message-queue/figure-13-the-choice-of-the-batch-size-EERC6LE5.svg)

The **batch size** introduces a tradeoff between **throughput** and **latency**:

- **Large Batch Size**:
  - **Increases Throughput**: More messages are sent in a single request.
  - **Higher Latency**: Waiting longer to accumulate messages into a batch.

- **Small Batch Size**:
  - **Lower Latency**: Messages are sent more frequently, reducing wait times.
  - **Reduced Throughput**: Smaller batch sizes result in lower network efficiency.

Producers can adjust the batch size based on their specific use case needs—prioritizing either high throughput or low latency.

---

By integrating the routing and buffering into the producer, the system minimizes latency and maximizes throughput through efficient batching. The design offers flexibility in partition assignment and provides producers with the tools to optimize performance based on their unique requirements.



# Consumer Flow

In the consumer flow, a consumer specifies its **offset** in a partition and receives a batch of events starting from that position.

![Figure 14 Consumer flow](https://bytebytego.com/images/courses/system-design-interview/distributed-message-queue/figure-14-consumer-flow-R7FTOUWG.svg)

## Push vs. Pull Models

### **Push Model**
- **Pros**:
  - **Low latency**: Brokers push messages to consumers immediately upon receiving them.
  
- **Cons**:
  - **Overwhelming Consumers**: If consumers process messages slower than production, they may get overwhelmed.
  - **Diverse Consumer Processing Power**: Difficult to accommodate consumers with varying processing speeds, as brokers control the rate of data transfer.

### **Pull Model**
- **Pros**:
  - **Consumer Control**: Consumers control the rate of consumption, which allows for real-time or batch processing.
  - **Scalability**: If consumption lags behind production, more consumers can be added or consumers can catch up later.
  - **Batch-Friendly**: Consumers can pull large batches of messages when ready, unlike the push model which may overwhelm consumers with frequent pushes.

- **Cons**:
  - **Wasted Resources**: If no messages are available, consumers may continue polling, wasting resources.
  - **Solution**: Use **long polling**, where the pull waits a certain amount of time for new messages to arrive before returning.

**Conclusion**: Most message queues adopt the **pull model**, which is more flexible and suitable for batch processing.

---

## Consumer Pull Workflow

![Figure 15 Pull model](https://bytebytego.com/images/courses/system-design-interview/distributed-message-queue/figure-15-pull-model-R7AR2RKW.svg)

1. **Joining the Consumer Group**:
   - A new consumer joins **group 1** and subscribes to **topic A**.
   - The consumer locates the corresponding **broker** by hashing the group name. All consumers in the same group connect to the same broker, which acts as the **coordinator** for that group (not to be confused with the broker cluster coordination service).
   
2. **Partition Assignment**:
   - The coordinator confirms the consumer's membership and assigns **partition 2** to the consumer.
   - **Partition Assignment Strategies**: Various strategies like round-robin or range can be used for partition assignment.

3. **Fetching Messages**:
   - The consumer fetches messages from its last consumed offset, which is managed by the **state storage**.

4. **Processing and Committing Offsets**:
   - The consumer processes the fetched messages and **commits** the offset to the broker after processing.
   - The sequence of processing and offset committing impacts the **message delivery semantics** (e.g., at-least-once, exactly-once), which will be discussed further.

---

### **Pull Model Benefits**

- Consumers pull messages at their own pace, making it more adaptable to different processing power and workloads.
- Suitable for **batch processing**, as consumers can pull large chunks of data rather than receiving frequent small pushes from brokers.
- **Long polling** reduces wasted resource usage when no messages are available by allowing the consumer to wait for new messages.

The **pull model** is the preferred approach in most message queue systems because it balances flexibility, scalability, and efficiency in handling varying consumer speeds and workloads.



# Consumer Rebalancing

**Consumer rebalancing** determines which consumer is responsible for which subset of partitions in a message queue. Rebalancing can occur when a consumer joins, leaves, crashes, or when partitions are adjusted.

## **Coordinator Role**

- The **coordinator** is a broker responsible for managing consumer rebalancing. It tracks consumer heartbeats and offsets.
- Consumers from the same group connect to the same coordinator by hashing the group name. The coordinator maintains a list of joined consumers.

### **Rebalancing Process**

1. **Consumer Group Leader**: When consumers join a group, the coordinator elects a leader.
2. **Partition Dispatch Plan**: The leader generates a partition dispatch plan and sends it to the coordinator, which broadcasts it to other consumers.
3. **Rebalance Trigger**: If a consumer fails to send a heartbeat, the coordinator initiates a rebalance, redistributing partitions among the remaining consumers.

## **Rebalance Scenarios**

![Figure 16 Coordinator of consumer groups](https://bytebytego.com/images/courses/system-design-interview/distributed-message-queue/figure-16-coordinator-of-consumer-groups-NBLTTJF7.svg)

1. **New Consumer Joins**:
   - When a new consumer joins, the coordinator notifies the group for rebalancing.
   - A new leader is elected, creates the dispatch plan, and partitions are redistributed.

2. **Existing Consumer Leaves**:
   - When a consumer leaves, the coordinator notifies the group.
   - The remaining consumer becomes the leader and the partitions are reassigned.

3. **Consumer Crashes**:
   - If a consumer crashes and the coordinator doesn't receive a heartbeat, it marks the consumer as dead.
   - The rebalance process is triggered, and the remaining consumers take over the crashed consumer's partitions.

The coordinator ensures dynamic rebalancing in various failure or scaling scenarios, keeping the system fault-tolerant and balanced.

![Figure 17 Consumer rebalance](https://bytebytego.com/images/courses/system-design-interview/distributed-message-queue/figure-17-consumer-rebalance-TXRF6U5L.svg)





![Figure 18 New consumer joins](https://bytebytego.com/images/courses/system-design-interview/distributed-message-queue/figure-18-new-consumer-joins-RTLIWBQS.svg)





![Figure 20 Existing consumer crashes](https://bytebytego.com/images/courses/system-design-interview/distributed-message-queue/figure-20-existing-consumer-crashes-TCUIE3U5.svg)



# ZooKeeper in Distributed Message Queue Design

**ZooKeeper** is a critical service for distributed systems, providing a hierarchical key-value store that supports **configuration management**, **synchronization**, and **naming registry**.

### **Key Changes with ZooKeeper (Figure 22)**:

![Figure 22 Zookeeper](https://bytebytego.com/images/courses/system-design-interview/distributed-message-queue/figure-22-zookeeper-UZGQ22ZY.svg)

1. **Metadata and State Storage**: 
   - Moved to ZooKeeper, allowing brokers to focus solely on **data storage** for messages.
   
2. **Leader Election**:
   - ZooKeeper simplifies **leader election** within the broker cluster, ensuring fault tolerance and proper coordination among brokers.

### **Benefits**:
- By offloading metadata and state management to ZooKeeper, the design becomes more streamlined, reducing complexity in the broker and improving system robustness.



# Replication in Distributed Message Queues

Replication is essential in distributed systems to achieve **high availability** and **fault tolerance**. By replicating data across multiple brokers, the system ensures that data remains accessible even if individual brokers fail.

## **Key Concepts**

### **1. Replica Distribution Plan**

- **Definition**: Determines how replicas of each partition are distributed across different broker nodes.
- **Example Plan**:
  - **Partition 1 of Topic A**: 
    - **Leader**: Broker 1
    - **Followers**: Broker 2, Broker 3
  - **Partition 2 of Topic A**: 
    - **Leader**: Broker 2
    - **Followers**: Broker 3, Broker 4
  - **Partition 1 of Topic B**: 
    - **Leader**: Broker 3
    - **Followers**: Broker 4, Broker 1
- **Coordinator Role**:
  - A designated broker (leader) generates the replica distribution plan.
  - The plan is persisted in **metadata storage**.
  - All brokers adhere to the distribution plan to maintain consistency.

### **2. Leader and Follower Replicas**

- **Leader Replica**:
  - Handles all **write operations** from producers.
  - Ensures message durability by coordinating with follower replicas.
- **Follower Replicas**:
  - **Pull** new messages from the leader.
  - Maintain copies of the leader’s data to ensure redundancy.

### **3. In-Sync Replicas (ISR)**

- **Definition**: Replicas that are "in-sync" with the leader, meaning they have caught up to the leader's latest messages within a configured threshold.
- **Configuration Example**:
  - `replica.lag.max.messages = 4`: A follower can lag by up to 3 messages and still remain in the ISR.
- **Functionality**:
  - Only ISRs are eligible to be elected as new leaders in case the current leader fails.
  - Ensures a balance between **performance** and **durability**.

### **4. Acknowledgment Settings**

Producers can configure how acknowledgments are handled to balance between **latency** and **durability**:

- **ACK=all**:
  
- ![Figure 25 ack=all](https://bytebytego.com/images/courses/system-design-interview/distributed-message-queue/figure-25-ack-all-O4UUVPX5.svg)
  - **Behavior**: Producer receives an acknowledgment only after all ISRs have received the message.
  - **Pros**: Strongest durability; no message loss as all replicas have the message.
  - **Cons**: Higher latency due to waiting for all replicas to synchronize.
  
- **ACK=1**:
  
- ![Figure 26 ack=1](https://bytebytego.com/images/courses/system-design-interview/distributed-message-queue/figure-26-ack-1-MPIADGCG.svg)
  - **Behavior**: Producer receives an acknowledgment once the leader has persisted the message.
  - **Pros**: Lower latency; faster acknowledgments.
  - **Cons**: Potential message loss if the leader fails before followers synchronize.
  
- **ACK=0**:
  
- ![Figure 27 ack=0](https://bytebytego.com/images/courses/system-design-interview/distributed-message-queue/figure-27-ack-0-KMQEZDTJ.svg)
  - **Behavior**: Producer sends messages without waiting for any acknowledgment.
  - **Pros**: Lowest latency; suitable for high-throughput scenarios where occasional message loss is acceptable (e.g., logging, metrics).
  - **Cons**: High risk of message loss as no acknowledgments are received.

## **Replication Workflow**

1. **Message Production**:
   - Producer sends a message to the **leader replica** of a specific partition.
2. **Replication**:
   - **Follower replicas** pull the message from the leader.
3. **Acknowledgment**:
   - Once the message is replicated to the required number of ISRs, the leader sends an acknowledgment to the producer based on the configured ACK setting.
4. **Data Persistence**:
   - Messages are persisted on disk by the leader and replicated to followers to ensure durability.

## **Consumer Side Considerations**

- **Connection to Leader**:
  - Consumers typically connect to the **leader replica** to consume messages.
  - **Advantages**:
    - Simplifies the design by limiting the number of connections to the leader.
    - Maintains order as messages are consumed from a single source.
- **Handling Hot Partitions**:
  - If a partition is highly active, it can be split into more partitions to distribute the load across multiple consumers and brokers.
- **Cross-Data Center Consumption**:
  - In scenarios where consumers are in different data centers, it might be beneficial to allow consumers to read from the closest ISR to reduce latency.

## **Why In-Sync Replicas (ISR) Matter**

- **Performance vs. Durability**:
  - **High Durability**: Ensures no data loss by requiring all (or a majority of) replicas to have the message before acknowledgment.
  - **High Performance**: Reduces latency by requiring fewer replicas to acknowledge the message, allowing faster processing.
- **Acknowledgment Flexibility**:
  - Configurable ACK settings allow producers to choose the desired balance between performance and data safety based on their specific use cases.

## **Summary**

- **Replication** enhances system reliability by ensuring multiple copies of each partition exist across different brokers.
- **In-Sync Replicas (ISR)** are crucial for maintaining data consistency and determining fault tolerance.
- **Acknowledgment settings** provide flexibility to balance between message durability and system performance.
- **Consumer connections** to leader replicas simplify consumption but can be optimized further based on deployment scenarios.

By carefully designing the replication strategy and acknowledgment mechanisms, a distributed message queue can achieve high availability, fault tolerance, and optimal performance tailored to various application needs.



# Scalability

Having designed the distributed message queue system, the next step is to evaluate the **scalability** of its various components:

- **Producers**
- **Consumers**
- **Brokers**
- **Partitions**

## **Producers**

- **Simplicity**: Producers are conceptually simpler than consumers as they do not require group coordination.
- **Scalability**: Easily scalable by adding or removing producer instances as needed.

## **Consumers**

- **Consumer Groups**: Consumers are organized into groups, allowing isolated scaling.
- **Rebalancing Mechanism**: 
  - Handles scenarios where consumers are added, removed, or crash.
  - Ensures scalability and fault tolerance within consumer groups.

## **Brokers**

### **Failure Recovery**

![Figure 28 Broker node crashes](https://bytebytego.com/images/courses/system-design-interview/distributed-message-queue/figure-28-broker-node-crashes-AVEQQUXB.svg)

- **Example Scenario**:
  - **Initial Setup**:
    - 4 brokers with the following replica distribution:
      - **Partition 1 of Topic A**: Broker 1 (leader), Broker 2, Broker 3
      - **Partition 2 of Topic A**: Broker 2 (leader), Broker 3, Broker 4
      - **Partition 1 of Topic B**: Broker 3 (leader), Broker 4, Broker 1
  - **Failure Event**: Broker 3 crashes.
  - **Updated Distribution Plan**:
    - **Partition 1 of Topic A**: Broker 1 (leader), Broker 2, Broker 4 (new)
    - **Partition 2 of Topic A**: Broker 2 (leader), Broker 4, Broker 1 (new)
    - **Partition 1 of Topic B**: Broker 4 (leader), Broker 1, Broker 2 (new)
  - **Recovery Process**:
    - The broker controller detects the crash.
    - Generates a new replica distribution plan.
    - New replicas catch up with the leader to ensure data consistency.

### **Fault-Tolerant Design Considerations**

![Figure 29 Add new broker node](https://bytebytego.com/images/courses/system-design-interview/distributed-message-queue/figure-29-add-new-broker-node-M6LJQ27W.svg)

- **Minimum In-Sync Replicas (ISR)**:
  - Defines how many replicas must synchronize before a message is considered committed.
  - Balances **latency** and **safety**.
  
- **Replica Distribution**:
  - **Avoid Same Node Replication**: Replicas should not reside on the same broker to prevent data loss from single node failures.
  - **Cross-Data Center Replication**: Enhances data safety but increases latency and cost.
  
- **Adding/Removing Brokers**:
  - **Graceful Addition**:
    - Broker controller allows temporary over-replication.
    - New broker catches up by copying data from existing leaders.
    - Redundant replicas are removed post synchronization.
  - **Graceful Removal**:
    - Reassign partitions to remaining brokers.
    - Ensure data consistency and availability during the transition.

## **Partitions**

### **Scaling Partitions**

**Figure 30: Partition Increase** *(Note: Figure not displayed)*

- **Increasing Partitions**:
  - **Process**:
    - Add a new partition to the topic.
    - New messages are persisted in all existing and new partitions.
    - No data migration is required; existing data remains in old partitions.
  - **Benefits**:
    - Simplifies scaling by allowing new partitions to handle additional load.
    - Producers and consumers are notified to adjust their operations accordingly.

### **Decreasing Partitions**

**Figure 31: Partition Decrease** *(Note: Figure not displayed)*

- **Challenges**:
  - Decommissioning partitions requires ensuring that no active consumers are processing data from them.
  - Data from decommissioned partitions cannot be immediately removed to prevent data loss.
  
- **Process**:
  1. **Decommission Partition**:
     - Stop accepting new messages for the partition.
     - Allow existing consumers to finish processing current messages.
  2. **Retention Period**:
     - Wait for the configured retention period before truncating data.
     - Ensures that no active processing is affected.
  3. **Rebalancing**:
     - Trigger consumer group rebalancing to adjust to the new partition configuration.
  
- **Considerations**:
  - Avoid data loss by respecting retention periods.
  - Maintain system stability during the transition.

## **Summary of Scalability**

- **Producers**: Scalable by simply adding/removing instances without complex coordination.
- **Consumers**: Scalable through consumer groups and an effective rebalance mechanism.
- **Brokers**: 
  - Ensure fault tolerance with leader and follower replicas.
  - Handle broker failures by redistributing partitions and maintaining data consistency.
  - Facilitate scalability by allowing dynamic addition/removal of brokers with minimal data loss.
- **Partitions**:
  - Enable horizontal scaling by increasing the number of partitions.
  - Manage complexity when decreasing partitions by ensuring data integrity and proper consumer rebalancing.

By carefully designing each component with scalability in mind, the distributed message queue system can efficiently handle increasing loads, ensure high availability, and maintain performance across various operational scenarios.







## Stock Exchange

### Summary of Exchange System Design Problem

**Functional Requirements:**
- **Securities Traded:** 
  - Stocks only.
- **Supported Operations:** 
  - Placing new limit orders.
  - Canceling existing orders.
- **Order Types:** 
  - Limit orders exclusively.
- **Trading Hours:** 
  - Only during regular trading hours (9:30 am to 4:00 pm).
- **Basic Functions:**
  - Clients can place and cancel limit orders.
  - Clients receive real-time trade matches.
  - Clients can view a live order book for up to 100 stock symbols.

**Scale Requirements:**
- **Users:** 
  - Tens of thousands of concurrent users.
- **Stock Symbols:** 
  - At least 100.
- **Trading Volume:** 
  - Approximately 1 billion orders per day.
- **Queries Per Second (QPS):**
  - **Average:** ~43,000 QPS.
  - **Peak:** ~215,000 QPS during opening and closing hours.

**Non-Functional Requirements:**
- **Availability:** 
  - 99.99% uptime.
- **Fault Tolerance:** 
  - Fast recovery mechanisms to minimize incident impact.
- **Latency:** 
  - Millisecond-level round-trip latency.
  - Focus on minimizing the 99th percentile latency.
- **Security:**
  - **KYC (Know Your Customer):** 
    - Mandatory verification checks.
  - **DDoS Protection:** 
    - Measures to prevent Distributed Denial of Service attacks.
  - **Account and Fund Management:** 
    - Ensure users have sufficient funds for orders.
    - Withhold funds for pending orders.

**Risk Checks:**
- **Trading Volume Limits:** 
  - Example: Maximum of 1 million shares per day for Apple stock.

**Key Challenges:**
- **High Throughput:** 
  - Managing billions of orders daily with real-time processing.
- **Real-Time Processing:** 
  - Ensuring immediate trade matches and order book updates.
- **Robust Fault Tolerance:** 
  - Maintaining system resilience and rapid recovery.
- **Minimal Latency:** 
  - Achieving low latency to support high-frequency trading.
- **Security and Compliance:** 
  - Implementing stringent security measures and regulatory compliance.

Overall, the system must efficiently handle high volumes of real-time stock trading operations while ensuring reliability, security, and low latency to support a large and active user base.





### Step 2: Propose High-Level Design and Get Buy-In

Before delving into the high-level design of the exchange system, it's essential to understand fundamental business concepts and terminology related to trading platforms.

---

#### **Business Knowledge 101**

- **Broker**
  - **Role:** Acts as an intermediary between retail clients and the exchange.
  - **Examples:** Charles Schwab, Robinhood, E*TRADE, Fidelity.
  - **Functions:**
    - Provide user-friendly interfaces for placing trades.
    - Offer access to market data for retail users.

- **Institutional Client**
  - **Characteristics:**
    - Trade in large volumes using specialized trading software.
    - Diverse requirements based on their specific objectives.
  - **Examples:**
    - **Pension Funds:**
      - Aim for stable income.
      - Trade infrequently but in large volumes.
      - Require features like order splitting to minimize market impact.
    - **Hedge Funds:**
      - May focus on market making.
      - Earn income through commission rebates.
      - Necessitate low-latency trading capabilities, avoiding basic interfaces like web pages or mobile apps.

---

#### **Order Types**

- **Limit Order**
  - **Definition:** A buy or sell order with a specified price.
  - **Execution:** May not be immediately matched or could be partially filled.
  
- **Market Order**
  - **Definition:** An order to buy or sell without specifying a price.
  - **Execution:** Guaranteed to execute immediately at the prevailing market price.
  - **Trade-off:** Sacrifices cost predictability for execution certainty, useful in fast-moving markets.

---

#### **Market Data Levels**

- **L1 (Level 1) Data**
  - **Contents:**
    - Best bid price.
    - Best ask price.
    - Quantities available at those prices.
  - **Use Case:** Provides a quick snapshot of the highest buy and lowest sell prices.

- **L2 (Level 2) Data**
  - **Contents:**
    - Multiple price levels beyond the best bid and ask.
    - Additional depth of the order book.
  - **Use Case:** Offers more detailed insights into market depth and potential price movements.

- **L3 (Level 3) Data**
  - **Contents:**
    - Full order book with all price levels.
    - Queued quantities at each price level.
  - **Use Case:** Essential for high-frequency and institutional traders who need comprehensive market data.

---

#### **Candlestick Chart**

- **Definition:** A graphical representation of a stock's price movements over a specific time period.
- **Components:**
  - **Open Price:** The price at the beginning of the time interval.
  - **Close Price:** The price at the end of the time interval.
  - **High Price:** The highest price during the interval.
  - **Low Price:** The lowest price during the interval.
- **Time Intervals:**
  - Common intervals include one-minute, five-minute, one-hour, one-day, one-week, and one-month.
- **Use Case:** Helps traders analyze price trends and make informed trading decisions.

---

#### **FIX Protocol (Financial Information eXchange)**

- **Definition:** A vendor-neutral communications protocol established in 1991 for exchanging securities transaction information.
- **Purpose:** Facilitates standardized and efficient communication between financial institutions.
- **Example of a FIX Message:**
  ```
  8=FIX.4.2 | 9=176 | 35=8 | 49=PHLX | 56=PERS | 52=20071123-05:30:00.000 | 
  11=ATOMNOCCC9990900 | 20=3 | 150=E | 39=E | 55=MSFT | 167=CS | 
  54=1 | 38=15 | 40=2 | 44=15 | 58=PHLX EQUITY TESTING | 59=0 | 
  47=C | 32=0 | 31=0 | 151=15 | 14=0 | 6=0 | 10=128 |
  ```
- **Key Fields:**
  - **8:** Begin string (protocol version).
  - **35:** Message type.
  - **49:** Sender ID.
  - **56:** Target ID.
  - **55:** Symbol (e.g., MSFT for Microsoft).
  - **38:** Order quantity.
  - **44:** Price.
- **Use Case:** Ensures interoperability and efficient transaction processing across different trading platforms and institutions.

---

### **Key Takeaways for High-Level Design**

- **User Segmentation:**
  - Design interfaces and functionalities catering to both retail and institutional clients.
  - Ensure low-latency pathways for institutional clients requiring rapid execution.

- **Order Management:**
  - Implement robust handling for different order types, particularly limit and market orders.
  - Support advanced features like order splitting to accommodate institutional trading strategies.

- **Market Data Handling:**
  - Provide multiple levels of market data (L1, L2, L3) to serve diverse user needs.
  - Ensure real-time data processing and distribution with minimal latency.

- **Communication Protocols:**
  - Integrate FIX protocol for standardized and efficient transaction processing.
  - Ensure compatibility with various trading systems used by institutional clients.

- **Visualization Tools:**
  - Offer comprehensive charting tools like candlestick charts for user analysis.
  - Provide customizable time intervals to cater to different trading strategies.

By understanding these foundational concepts and requirements, the high-level design can effectively address the needs of diverse clients, ensure efficient order processing, and maintain robust communication protocols essential for a high-performance exchange system.





### High-Level Design Summary

#### **Overview**
The high-level design outlines the architecture of a stock exchange system, detailing the flow of orders, market data, and reporting. It emphasizes the critical trading path with stringent latency requirements and supports auxiliary processes for market data dissemination and reporting.

![Figure 6 High-level design](https://bytebytego.com/_next/image?url=%2Fimages%2Fcourses%2Fsystem-design-interview%2Fstock-exchange%2Ffigure-6-high-level-design-A3NJ5JVE.png&w=1920&q=75)

---

#### **Order Trading Flow**
This is the critical path with strict latency requirements, ensuring rapid processing of client orders.

1. **Order Placement**
   - **Step 1:** 
     - **Action:** Client places an order via the broker’s web or mobile application.
   
2. **Order Transmission**
   - **Step 2:** 
     - **Action:** Broker forwards the order to the exchange.
   
3. **Client Gateway Processing**
   - **Step 3:** 
     - **Components:**
       - **Client Gateway Responsibilities:**
         - Input validation
         - Rate limiting
         - Authentication
         - Normalization
     - **Action:** Forwards validated order to the Order Manager.
   
4. **Risk Management**
   - **Steps 4 - 5:** 
     - **Component:** Order Manager
     - **Action:** Performs risk checks based on rules defined by the Risk Manager.
   
5. **Fund Verification**
   - **Step 6:** 
     - **Action:** Order Manager verifies sufficient funds in the user’s wallet for the order.
   
6. **Order Matching**
   - **Steps 7 - 9:** 
     - **Component:** Matching Engine
     - **Actions:**
       - Processes the order to find matches.
       - Emits two executions (fills) for buy and sell sides.
       - Ensures deterministic matching by sequencing orders and executions in the Sequencer.
   
7. **Execution Return**
   - **Steps 10 - 14:** 
     - **Action:** Executions are sent back to the client through the broker.

---

#### **Market Data Flow**
Handles the dissemination of trade executions and order book updates to brokers and clients.

1. **Execution Stream Generation**
   - **Step M1:** 
     - **Component:** Matching Engine
     - **Action:** Generates a stream of executions (fills) as matches occur and sends it to the Market Data Publisher.
   
2. **Market Data Construction**
   - **Step M2:** 
     - **Component:** Market Data Publisher
     - **Actions:**
       - Constructs candlestick charts and order books from the execution stream.
       - Sends the compiled market data to the Data Service.
   
3. **Market Data Distribution**
   - **Step M3:** 
     - **Actions:**
       - Saves market data to specialized storage for real-time analytics.
       - Brokers connect to the Data Service to retrieve and relay market data to their clients.

---

#### **Reporting Flow**
Handles the collection and storage of transaction data for reporting and compliance purposes.

1. **Data Collection and Consolidation**
   - **Steps R1 - R2:** 
     - **Component:** Reporter
     - **Actions:**
       - Collects necessary reporting fields (e.g., client_id, price, quantity, order_type, filled_quantity, remaining_quantity) from orders and executions.
       - Writes consolidated records to the database.

---

#### **Key Components and Responsibilities**
- **Client Gateway:** Handles initial order intake, validation, and forwarding to the Order Manager.
- **Order Manager:** Conducts risk assessments and fund verification before processing orders.
- **Matching Engine:** Core component for order matching and execution generation.
- **Sequencer:** Ensures deterministic ordering and execution sequencing for reliability.
- **Market Data Publisher:** Transforms execution data into market data feeds like candlestick charts and order books.
- **Data Service:** Distributes real-time market data to brokers and clients.
- **Reporter:** Collects and stores transaction data for reporting and compliance.

---

#### **Latency and Performance Considerations**
- **Critical Path:** Trading flow (Steps 1-14) requires millisecond-level latency to ensure real-time processing.
- **Auxiliary Flows:** Market data flow and reporting flow have separate latency requirements, allowing for parallel processing without impacting the trading path.

---

#### **Key Challenges Addressed**
- **High Throughput:** Efficient handling of billions of daily orders and high QPS during peak trading times.
- **Real-Time Processing:** Immediate trade matching and order book updates to support dynamic trading environments.
- **Fault Tolerance:** Robust mechanisms to ensure system resilience and rapid recovery from incidents.
- **Security:** Ensuring secure transactions through authentication, risk checks, and fund verification.
- **Scalability:** Accommodating a large number of concurrent users and diverse client requirements (retail and institutional).

---

By mapping out the detailed flows and components, the high-level design ensures that the exchange system can handle high volumes of real-time stock trading operations efficiently while maintaining reliability, security, and low latency to support a large and active user base.





### Trading Flow Overview

The trading flow is the critical path of the exchange system, requiring ultra-low latency and high reliability. Central to this flow is the **Matching Engine**, supported by the **Sequencer** and **Order Manager** components.

---

#### **Matching Engine (Cross Engine)**

**Primary Responsibilities:**
- **Maintain Order Books:**
  - Manages buy and sell orders for each stock symbol.
  - Constructs and updates the order book based on incoming orders.
  
- **Match Orders:**
  - Pairs buy and sell orders to execute trades.
  - Generates two executions (fills) for each match: one for the buy side and one for the sell side.
  - Ensures matching is both fast and accurate.

- **Distribute Execution Stream:**
  - Sends executed trades as market data to downstream services.

**Key Characteristics:**
- **Deterministic Order Processing:**
  - Ensures that given the same sequence of orders, the matching engine produces the same sequence of executions.
  - Essential for high availability and consistency, especially during system recovery and replay scenarios.

---

#### **Sequencer**

![Figure 7 Inbound and outbound sequencers](https://bytebytego.com/images/courses/system-design-interview/stock-exchange/figure-7-inbound_and_outbound_sequencers-3MF75AIL.svg)

**Functionality:**
- **Sequence ID Assignment:**
  - **Inbound Sequencer:** Assigns a unique sequence ID to each incoming order before it reaches the matching engine.
  - **Outbound Sequencer:** Assigns sequence IDs to each pair of executions (fills) generated by the matching engine.

- **Message Queueing:**
  - Acts as a message broker for both incoming orders and outgoing executions.
  - Functions similarly to two Kafka event streams but optimized for lower and more predictable latency.

- **Event Storage:**
  - Serves as an event store, maintaining a reliable log of all orders and executions for replay and recovery.

**Benefits:**
- **Timeliness and Fairness:** Ensures orders are processed in the exact sequence they are received.
- **Fast Recovery/Replay:** Facilitates quick system recovery by replaying events in the same order.
- **Exactly-Once Guarantee:** Prevents duplicate processing of orders and executions.

---

#### **Order Manager**

**Responsibilities:**
- **Order Reception:**
  - **Inbound Orders:** Receives orders from the Client Gateway.
  - **Executions:** Receives executed trades from the Matching Engine via the Sequencer.

- **Risk Management:**
  - Performs risk checks, such as ensuring a user’s daily trade volume does not exceed predefined limits (e.g., $1M/day).

- **Fund Verification:**
  - Checks the user’s digital wallet to ensure sufficient funds are available for the order.
  - Withholds necessary funds for pending orders to prevent overcommitment.

- **Order Processing:**
  - Sends validated and verified orders to the Sequencer.
  - Transmits only essential order attributes to the Matching Engine to reduce data transmission size.

- **Execution Handling:**
  - Processes executions received from the Matching Engine.
  - Returns execution details to brokers via the Client Gateway.

**Design Considerations:**
- **Performance:** Must operate with high speed and efficiency to handle thousands of concurrent orders.
- **Accuracy:** Maintains precise states for all orders, managing complex state transitions reliably.
- **Scalability:** Capable of handling tens of thousands of state transitions and order states.

**Implementation Strategy:**
- **Event Sourcing:** Utilizes an event sourcing model to manage and track the state of orders, ensuring consistency and reliability across the system.

---

### **Key Components and Their Interactions**

- **Client Gateway:**
  - Entry point for incoming orders.
  - Performs initial validation and forwards orders to the Order Manager.

- **Order Manager:**
  - Conducts risk checks and fund verification.
  - Interfaces with the Sequencer to ensure orderly processing.

- **Sequencer:**
  - Assigns sequence IDs to orders and executions.
  - Acts as a message queue and event store for reliable processing.

- **Matching Engine:**
  - Core component responsible for order matching and trade execution.
  - Sends execution streams to the Market Data Publisher.

- **Market Data Publisher:**
  - Transforms execution data into market data feeds (e.g., candlestick charts, order books).
  - Distributes real-time market data to brokers and clients.

- **Reporter:**
  - Collects and consolidates transaction data for reporting and compliance.
  - Stores records in the database for audit and analysis purposes.

---

### **Latency and Performance Considerations**

- **Critical Path (Trading Flow Steps 1-14):**
  - Requires millisecond-level latency to ensure real-time processing.
  - All components involved must operate with minimal delay to maintain system performance.

- **Auxiliary Flows (Market Data and Reporting):**
  - Have separate latency requirements and can be processed in parallel.
  - Do not impact the critical trading path, allowing for efficient data dissemination and reporting without compromising trading performance.

---

### **Key Challenges Addressed**

- **High Throughput:**
  - Efficiently processes billions of orders daily with high QPS, especially during peak trading periods.

- **Real-Time Processing:**
  - Ensures immediate trade matching and updates to the order book, supporting dynamic and fast-paced trading environments.

- **Fault Tolerance:**
  - Maintains system resilience through deterministic processing and rapid recovery mechanisms.

- **Security:**
  - Implements robust authentication, risk checks, and fund verification to secure transactions and user accounts.

- **Scalability:**
  - Accommodates a large number of concurrent users and varying client requirements, from retail to institutional clients.

---

By meticulously designing the Matching Engine, Sequencer, and Order Manager, the trading flow ensures that the exchange system operates with the required speed, reliability, and accuracy to support high-frequency trading and maintain market integrity.





### Client Gateway Overview

The **Client Gateway** serves as the primary entry point for all client orders into the exchange system. It is a critical, latency-sensitive component designed to handle high volumes of transactions efficiently while ensuring security and proper routing of orders.

---

#### **Primary Functions of the Client Gateway**

- **Order Reception and Routing:**
  - **Receives Orders:** Accepts orders placed by clients through brokers' web or mobile applications.
  - **Routes Orders:** Directs orders to the appropriate destination, primarily the Order Manager.

- **Basic Gatekeeping Functions:**
  - **Input Validation:** Ensures that incoming orders meet the required format and criteria.
  - **Rate Limiting:** Controls the number of orders processed within a specific timeframe to prevent overload.
  - **Authentication:** Verifies the identity of clients to ensure secure access.
  - **Normalization:** Standardizes order data to maintain consistency across the system.

---

#### **Design Considerations**

- **Latency Sensitivity:**
  - **Lightweight Processing:** Minimizes processing within the gateway to reduce delay.
  - **Quick Order Forwarding:** Ensures orders are passed to downstream components as rapidly as possible.

- **Functionality Trade-offs:**
  - **Simplified Gateway:** Delegates complex processing tasks to other components like the Matching Engine and Risk Manager to maintain low latency.
  - **Essential vs. Complex Functions:** Balances which functions to implement within the gateway versus other parts of the system to optimize performance.

---

#### **Client Gateway Variants**

- **Retail Client Gateway:**
  - **Characteristics:**
    - Handles lower transaction volumes compared to institutional gateways.
    - Prioritizes user-friendly interfaces and accessibility.
  - **Security Requirements:**
    - Implements standard security measures suitable for individual traders.

- **Institutional Client Gateway:**
  - **Characteristics:**
    - Manages high transaction volumes with stringent latency requirements.
    - Supports specialized trading strategies and large order sizes.
  - **Security Requirements:**
    - Enhanced security protocols to protect high-value transactions and sensitive data.

---

#### **Specialized Client Gateway Connections**

- **Colocation (Colo) Engine:**
  - **Definition:** Trading engine software hosted on servers within the exchange’s data center, rented by brokers.
  - **Advantages:**
    - **Ultra-Low Latency:** Minimizes transmission delays by physically locating servers close to the exchange.
    - **Speed:** Achieves latencies comparable to the speed of light between colocated servers and the exchange.
  - **Use Case:** Primarily used by market makers and high-frequency trading firms that require the fastest possible execution times.

---

#### **Key Considerations for Client Gateway Design**

- **Performance:**
  - Must handle high transaction volumes without becoming a bottleneck.
  - Ensures rapid processing to maintain overall system latency targets.

- **Scalability:**
  - Capable of scaling to accommodate increasing numbers of clients and higher transaction rates.
  
- **Security:**
  - Implements robust authentication and authorization mechanisms to protect against unauthorized access.
  - Ensures data integrity and confidentiality for all transactions passing through the gateway.

- **Reliability:**
  - Maintains high availability to support continuous trading operations.
  - Incorporates fault-tolerant designs to prevent downtime and ensure consistent performance.

---

### **Key Takeaways for High-Level Design**

- **Efficiency:** The Client Gateway must process and route orders swiftly to support the critical trading flow.
- **Specialization:** Different gateways for retail and institutional clients cater to their unique requirements, such as latency and transaction volume.
- **Minimal Processing:** Keeps processing lightweight within the gateway, delegating complex tasks to other system components to maintain low latency.
- **Advanced Connectivity:** Utilizes specialized connections like colocation to achieve the lowest possible latency for high-frequency trading needs.

---

By meticulously designing the Client Gateway with these considerations, the exchange system ensures efficient, secure, and rapid handling of client orders, thereby supporting the overall performance and reliability of the trading platform.



### Client Gateway Overview

![Figure 8 Client gateway components](https://bytebytego.com/images/courses/system-design-interview/stock-exchange/figure-8-client-gateway-components-COTYQAOK.svg)

The **Client Gateway** serves as the primary entry point for all client orders into the exchange system. It is a critical, latency-sensitive component designed to handle high volumes of transactions efficiently while ensuring security and proper routing of orders.

---

#### **Primary Functions of the Client Gateway**

- **Order Reception and Routing:**
  - **Receives Orders:** Accepts orders placed by clients through brokers' web or mobile applications.
  - **Routes Orders:** Directs orders to the appropriate destination, primarily the Order Manager.

- **Basic Gatekeeping Functions:**
  - **Input Validation:** Ensures that incoming orders meet the required format and criteria.
  - **Rate Limiting:** Controls the number of orders processed within a specific timeframe to prevent overload.
  - **Authentication:** Verifies the identity of clients to ensure secure access.
  - **Normalization:** Standardizes order data to maintain consistency across the system.

---

#### **Design Considerations**

- **Latency Sensitivity:**
  - **Lightweight Processing:** Minimizes processing within the gateway to reduce delay.
  - **Quick Order Forwarding:** Ensures orders are passed to downstream components as rapidly as possible.

- **Functionality Trade-offs:**
  - **Simplified Gateway:** Delegates complex processing tasks to other components like the Matching Engine and Risk Manager to maintain low latency.
  - **Essential vs. Complex Functions:** Balances which functions to implement within the gateway versus other parts of the system to optimize performance.

---

#### **Client Gateway Variants**

![Figure 9 Client gateway](https://bytebytego.com/images/courses/system-design-interview/stock-exchange/figure-9-client-gateway-W5TCL3VV.svg)

- **Retail Client Gateway:**
  - **Characteristics:**
    - Handles lower transaction volumes compared to institutional gateways.
    - Prioritizes user-friendly interfaces and accessibility.
  - **Security Requirements:**
    - Implements standard security measures suitable for individual traders.

- **Institutional Client Gateway:**
  - **Characteristics:**
    - Manages high transaction volumes with stringent latency requirements.
    - Supports specialized trading strategies and large order sizes.
  - **Security Requirements:**
    - Enhanced security protocols to protect high-value transactions and sensitive data.

---

#### **Specialized Client Gateway Connections**

- **Colocation (Colo) Engine:**
  - **Definition:** Trading engine software hosted on servers within the exchange’s data center, rented by brokers.
  - **Advantages:**
    - **Ultra-Low Latency:** Minimizes transmission delays by physically locating servers close to the exchange.
    - **Speed:** Achieves latencies comparable to the speed of light between colocated servers and the exchange.
  - **Use Case:** Primarily used by market makers and high-frequency trading firms that require the fastest possible execution times.

---

#### **Key Considerations for Client Gateway Design**

- **Performance:**
  - Must handle high transaction volumes without becoming a bottleneck.
  - Ensures rapid processing to maintain overall system latency targets.

- **Scalability:**
  - Capable of scaling to accommodate increasing numbers of clients and higher transaction rates.
  
- **Security:**
  - Implements robust authentication and authorization mechanisms to protect against unauthorized access.
  - Ensures data integrity and confidentiality for all transactions passing through the gateway.

- **Reliability:**
  - Maintains high availability to support continuous trading operations.
  - Incorporates fault-tolerant designs to prevent downtime and ensure consistent performance.

---

### **Key Takeaways for High-Level Design**

- **Efficiency:** The Client Gateway must process and route orders swiftly to support the critical trading flow.
- **Specialization:** Different gateways for retail and institutional clients cater to their unique requirements, such as latency and transaction volume.
- **Minimal Processing:** Keeps processing lightweight within the gateway, delegating complex tasks to other system components to maintain low latency.
- **Advanced Connectivity:** Utilizes specialized connections like colocation to achieve the lowest possible latency for high-frequency trading needs.

---

By meticulously designing the Client Gateway with these considerations, the exchange system ensures efficient, secure, and rapid handling of client orders, thereby supporting the overall performance and reliability of the trading platform.





### Market Data Flow Overview

The **Market Data Flow** is responsible for processing and disseminating trade executions and market information to subscribers, including brokers and their clients. Central to this flow is the **Market Data Publisher (MDP)**, which transforms raw execution data into meaningful market insights such as order books and candlestick charts.

---

#### **Primary Components and Their Responsibilities**

- **Market Data Publisher (MDP)**
  - **Receives Executions:**
    - **Source:** Matching Engine.
    - **Content:** Streams of executions (fills) resulting from matched buy and sell orders.
  
  - **Builds Market Data:**
    - **Order Books:**
      - **Definition:** Lists of current buy and sell orders for each stock symbol.
      - **Function:** Provides a real-time view of market depth and liquidity.
    - **Candlestick Charts:**
      - **Definition:** Graphical representations of stock price movements over specified time intervals.
      - **Components:** Open, close, high, and low prices for each interval.
      - **Function:** Helps traders analyze price trends and make informed trading decisions.
  
  - **Transforms Execution Streams:**
    - Converts raw execution data into structured market data formats (order books and candlestick charts).

- **Data Service**
  - **Receives Market Data from MDP:**
    - **Function:** Acts as a distribution hub for processed market data.
  
  - **Makes Market Data Available to Subscribers:**
    - **Subscribers:** Brokers, institutional clients, and retail clients.
    - **Access:** Provides real-time access to order books and candlestick charts for informed trading.

---

#### **Market Data Flow Steps**

![Figure 10 Market Data Publisher](https://bytebytego.com/images/courses/system-design-interview/stock-exchange/figure-10-market-data-publisher-NW4AZKEC.svg)

1. **Execution Stream Generation**
   - **Step:** Matching Engine generates a continuous stream of executions as trades are matched.
   - **Action:** Sends the execution stream to the Market Data Publisher (MDP).

2. **Market Data Construction**
   - **Step:** MDP processes the execution stream.
   - **Actions:**
     - **Builds Order Books:** Aggregates buy and sell orders to create real-time order books for each stock symbol.
     - **Creates Candlestick Charts:** Compiles price data into candlestick charts for various time intervals.

3. **Market Data Distribution**
   - **Step:** MDP sends the constructed market data to the Data Service.
   - **Actions:**
     - **Storage:** Saves market data to specialized storage systems optimized for real-time analytics.
     - **Distribution:** Enables brokers to connect to the Data Service and retrieve timely market data.
     - **Relay to Clients:** Brokers forward the market data to their respective clients, ensuring that traders have access to the latest market information.

---

#### **Design Considerations**

- **Real-Time Processing:**
  - **Requirement:** Market data must be processed and disseminated with minimal latency to ensure timely information for traders.
  - **Implementation:** Optimized data pipelines and efficient processing algorithms within the MDP.

- **Scalability:**
  - **Requirement:** Ability to handle high volumes of execution data and support numerous subscribers simultaneously.
  - **Implementation:** Distributed architectures and scalable storage solutions to accommodate growing data and user bases.

- **Reliability:**
  - **Requirement:** Ensures continuous availability of market data even during high-load periods or partial system failures.
  - **Implementation:** Redundant systems and fault-tolerant designs within the MDP and Data Service.

- **Data Accuracy:**
  - **Requirement:** Accurate construction of order books and candlestick charts to maintain market integrity and trust.
  - **Implementation:** Robust data validation and consistency checks within the MDP.

---

### **Key Takeaways for High-Level Design**

- **Efficient Data Transformation:**
  - The MDP must swiftly convert raw execution streams into structured market data to support real-time trading activities.

- **Seamless Data Distribution:**
  - The Data Service acts as a central repository and distribution point, ensuring that all subscribers receive up-to-date market information without delay.

- **Scalable and Reliable Architecture:**
  - Designing the Market Data Flow with scalability and reliability in mind ensures that the exchange can handle increasing data volumes and maintain continuous operations.

- **Support for Diverse Market Data Needs:**
  - By providing both order books and candlestick charts, the system caters to various trading strategies and analytical requirements of different clients.

---

By effectively implementing the Market Data Flow, the exchange system ensures that all participants have access to accurate and timely market information, which is crucial for making informed trading decisions and maintaining the overall health and efficiency of the trading ecosystem.



### Reporting Flow Overview

![Figure 11 Reporter](https://bytebytego.com/images/courses/system-design-interview/stock-exchange/figure-11-reporter-OKUG5GXU.svg)

The **Reporting Flow** is a critical, though non-latency-sensitive, part of the exchange system. It is responsible for compiling trading history, tax reporting, compliance reports, and settlements. Unlike the real-time trading flow, the reporting flow prioritizes **accuracy** and **compliance** over speed.

---

#### **Key Functions of the Reporting Flow**

- **Trade History:**
  - Records and stores a complete history of all trades for reference and auditing purposes.
  
- **Tax and Compliance Reporting:**
  - Generates reports needed for regulatory compliance and tax obligations.
  
- **Settlements:**
  - Facilitates post-trade settlements by providing accurate records of executed trades.

---

#### **Data Merging Process**

- **Order and Execution Data:**
  - **Incoming Orders:** Contains details like order type, client ID, and requested quantity.
  - **Outgoing Executions:** Contains details such as order ID, execution price, quantity, and status.
  
- **Merging Attributes:**
  - The reporter merges attributes from both incoming orders and outgoing executions to generate comprehensive reports. This includes combining order details with execution data to create complete records of each trade.

---

#### **Design Considerations**

- **Latency:** 
  - While less sensitive to latency compared to the trading flow, the reporter must still ensure timely generation of reports to meet regulatory deadlines.
  
- **Accuracy:** 
  - Reports must be accurate, ensuring all regulatory and tax obligations are met without errors.

- **Compliance:** 
  - Ensures that all reporting adheres to financial regulations and industry standards, supporting transparency and accountability.

---

### **Key Takeaways for High-Level Design**

- **Non-Critical Path:** 
  - The reporter is not part of the real-time trading path, but it is crucial for maintaining regulatory and financial compliance.
  
- **Data Merging:** 
  - The reporter efficiently merges attributes from both incoming orders and outgoing executions to create detailed reports.

- **Accuracy and Compliance Focus:** 
  - Prioritizes precision in generating reports to ensure full compliance with regulatory standards.

By ensuring accurate and compliant reporting, the **Reporting Flow** supports the integrity of the exchange system while handling post-trade activities such as settlements, tax filings, and compliance audits.





### API Design Overview

The API allows clients to interact with the stock exchange via brokers for placing orders, viewing executions, accessing market data, and downloading historical data for analysis. It follows **RESTful conventions** for the client gateway. While REST is suitable for most use cases, institutional clients with strict latency requirements might use different protocols.

---

#### **Key API Endpoints**

1. **Place Order (POST /v1/order)**
   - **Function:** Places a new order.
   - **Parameters:** 
     - `symbol` (String), `side` (buy/sell), `price` (Long), `orderType` (limit only), `quantity` (Long).
   - **Response:** 
     - Contains the `orderId`, `creationTime`, `filledQuantity`, `remainingQuantity`, `status` (new/canceled/filled), and input parameters.
   - **Status Codes:** 
     - 200 (success), 40x (parameter error, unauthorized), 500 (server error).

2. **View Executions (GET /execution)**
   - **Function:** Queries execution details.
   - **Parameters:** 
     - `symbol` (String), `orderId` (Optional), `startTime`, `endTime` (Long, in epoch).
   - **Response:** 
     - Array of executions with attributes like `id`, `orderId`, `symbol`, `side`, `price`, `quantity`, etc.
   - **Status Codes:** 
     - 200 (success), 40x (parameter error, not found, unauthorized), 500 (server error).

3. **Order Book (GET /marketdata/orderBook/L2)**
   - **Function:** Queries Level 2 order book data.
   - **Parameters:** 
     - `symbol` (String), `depth` (Int).
   - **Response:** 
     - Arrays of `bids` and `asks` with price and size.
   - **Status Codes:** 
     - 200 (success), 40x (parameter error, not found, unauthorized), 500 (server error).

4. **Historical Prices (GET /marketdata/candles)**
   - **Function:** Queries candlestick chart data for a symbol.
   - **Parameters:** 
     - `symbol` (String), `resolution` (in seconds), `startTime`, `endTime` (Long, in epoch).
   - **Response:** 
     - Array of candlestick data (`open`, `close`, `high`, `low` prices).
   - **Status Codes:** 
     - 200 (success), 40x (parameter error, not found, unauthorized), 500 (server error).

---

### **Key Points**
- **Order Placement:** Supports creating limit orders with all essential details (symbol, price, quantity).
- **Execution Queries:** Allows querying for execution details within a time range, including order status and prices.
- **Order Book Access:** Provides Level 2 market data for in-depth analysis of buy/sell orders.
- **Historical Data:** Offers candlestick chart data for analyzing past price trends over different time resolutions.

This API design provides essential functionalities for client-broker interactions with focus on flexibility, accuracy, and accessibility for both retail and institutional traders.



### Data Models Overview

In the stock exchange system, there are three primary types of data essential for its operation: **Product, Order, and Execution**, **Order Book**, and **Candlestick Chart**. Each plays a distinct role in facilitating trading, market analysis, and reporting.

---

#### **1. Product, Order, and Execution**

- **Product**
  - **Definition:** Describes the attributes of a traded symbol.
  - **Attributes:**
    - Product type
    - Trading symbol
    - UI display symbol
    - Settlement currency
    - Lot size
    - Tick size
    - **Characteristics:**
      - **Static Data:** Rarely changes, primarily used for UI display.
      - **Storage:** Can be stored in any database and is highly cacheable for quick access.

- **Order**
  - **Definition:** Represents an inbound instruction to buy or sell a stock.
  - **Attributes:**
    - Symbol
    - Side (buy/sell)
    - Price
    - Order type (limit)
    - Quantity
  - **Characteristics:**
    - **Lifecycle:** Not all orders result in executions.
    - **Flow Involvement:** Integral to all three system flows (trading, market data, reporting).

- **Execution**
  - **Definition:** Represents the matched result of an order, also known as a fill.
  - **Attributes:**
    - Execution ID
    - Order ID
    - Symbol
    - Side (buy/sell)
    - Price
    - Quantity
    - Execution status
  - **Characteristics:**
    - **Multiplicity:** Each matched order generates two executions (one for buy, one for sell).
    - **Flow Involvement:** Critical for trading, market data, and reporting flows.

- **Relationships:**
  - **Logical Model:** Orders and Executions are interconnected, where each order can result in one or multiple executions.
  - **Note:** The logical model (Figure 12) illustrates these relationships but does not represent the actual database schema.

---

#### **2. Order Book**

- **Definition:** A comprehensive list of all buy and sell orders for each stock symbol.
- **Components:**
  - **Bids:** Buy orders sorted by price and time.
  - **Asks:** Sell orders sorted by price and time.
- **Function:**
  - Provides real-time visibility into market depth and liquidity.
  - Essential for traders to make informed decisions based on current supply and demand.

---

#### **3. Candlestick Chart**

- **Definition:** A graphical representation of a stock's price movements over specific time intervals.
- **Components:**
  - **Open Price:** Price at the start of the interval.
  - **Close Price:** Price at the end of the interval.
  - **High Price:** Highest price during the interval.
  - **Low Price:** Lowest price during the interval.
- **Time Intervals:**
  - Common resolutions include one-minute, five-minute, one-hour, one-day, one-week, and one-month.
- **Function:**
  - Helps traders analyze price trends and volatility.
  - Facilitates technical analysis for making trading decisions.

---

#### **Data Storage and Processing Considerations**

- **Critical Trading Path:**
  - **In-Memory Processing:** Orders and executions are processed in memory to achieve high performance and low latency.
  - **Sequencer Storage:** 
    - **Purpose:** Stores orders and executions for fast recovery.
    - **Mechanism:** Utilizes hard disk or shared memory for persistence and sharing.
  - **Data Archiving:** Post-market close, data is archived for long-term storage and analysis.

- **Reporting Flow:**
  - **Database Storage:** 
    - **Function:** The reporter consolidates and writes orders and executions to a database.
    - **Use Cases:** Facilitates reconciliation, tax reporting, compliance reporting, and settlements.
  - **Data Merging:** Combines attributes from incoming orders and outgoing executions to generate comprehensive reports.

- **Market Data Processor:**
  - **Function:** Receives executions from the matching engine to reconstruct order books and candlestick charts.
  - **Output:** Provides structured market data for real-time analytics and client access.

---

### **Key Takeaways**

- **Diverse Data Types:** Understanding the distinct roles of products, orders, executions, order books, and candlestick charts is crucial for designing a robust exchange system.
- **Efficient Data Handling:** High-performance in-memory processing and strategic data storage ensure low latency and quick recovery in the critical trading path.
- **Comprehensive Reporting:** Accurate and compliant reporting relies on merging detailed order and execution data, stored efficiently for regulatory and analytical purposes.
- **Real-Time Market Insights:** The construction and distribution of order books and candlestick charts provide essential market data for traders and analysts, enhancing decision-making processes.

By effectively managing these data models, the stock exchange system ensures seamless trading operations, accurate market data dissemination, and reliable reporting mechanisms essential for maintaining market integrity and compliance.





### Order Book Overview

An **Order Book** is a fundamental data structure in a stock exchange system, maintaining a list of buy and sell orders for a specific security or financial instrument, organized by price levels. It is pivotal for the matching engine to facilitate fast and efficient order matching.



![Figure 13 Limit order book illustrated](https://bytebytego.com/images/courses/system-design-interview/stock-exchange/figure-13-limit-order-book-illustrated-4HLSPSXB.svg)

---

#### **Key Requirements for an Efficient Order Book**

- **Constant Lookup Time:**
  - **Operations:** Retrieve volume at specific price levels or across multiple levels.
  
- **Fast Add/Cancel/Execute Operations:**
  - **Time Complexity:** Preferably O(1) for placing new orders, canceling existing orders, and matching orders.
  
- **Fast Updates:**
  - **Operation:** Replace or modify existing orders swiftly.
  
- **Query Best Bid/Ask:**
  - **Function:** Quickly identify the highest buy price (best bid) and the lowest sell price (best ask).
  
- **Iterate Through Price Levels:**
  - **Function:** Traverse through different price levels efficiently for analysis or processing.
  
---

#### **Order Book Structure and Implementation**

##### **Initial Implementation**

```java
class PriceLevel {
    private Price limitPrice;
    private long totalVolume;
    private List<Order> orders;
}

class Book<Side> {
    private Side side;
    private Map<Price, PriceLevel> limitMap;
}

class OrderBook {
    private Book<Buy> buyBook;
    private Book<Sell> sellBook;
    private PriceLevel bestBid;
    private PriceLevel bestOffer;
    private Map<OrderID, Order> orderMap;
}
```

- **Components:**
  - **PriceLevel:** Represents a specific price point with total volume and a list of orders.
  - **Book:** Manages buy or sell orders using a map of price levels.
  - **OrderBook:** Combines buy and sell books, tracks best bid and offer, and maintains a map for quick order lookup.
  
##### **Performance Analysis**

- **Add/Cancel Operations:**
  - **Current Issue:** Using a plain `List<Order>` results in O(n) time complexity for deletion operations.
  
- **Optimized Solution:**
  - **Data Structure Change:** Replace `List<Order>` with a **doubly-linked list** to achieve O(1) time complexity for add, cancel, and execute operations.
  
- **Achieving O(1) Time Complexity:**
  - **Placing a New Order:** Add to the tail of the doubly-linked list (O(1)).
  - **Matching an Order:** Remove from the head of the doubly-linked list (O(1)).
  - **Canceling an Order:** Use `Map<OrderID, Order>` to locate and remove the order directly without traversal (O(1)).
  
---

#### **Example Order Execution**

**Scenario:**

- **Action:** A large market buy order for 2,700 shares of Apple is placed.
- **Process:**
  1. **Matching:** The buy order matches all existing sell orders in the best ask queue.
  2. **Partial Match:** It partially matches the first sell order at the next price level (100.11).
  3. **Result:** After fulfilling the large buy order, the bid/ask spread widens, and the best ask price increases to 100.11.
  

**Illustration:**

- **Figure 13:** Demonstrates the matching process and the resulting state of the order book after execution.
  
---

#### **Optimized Order Book Code Snippet**

```java
class PriceLevel {
    private Price limitPrice;
    private long totalVolume;
    private DoublyLinkedList<Order> orders; // Changed to DoublyLinkedList
}

class Book<Side> {
    private Side side;
    private Map<Price, PriceLevel> limitMap;
}

class OrderBook {
    private Book<Buy> buyBook;
    private Book<Sell> sellBook;
    private PriceLevel bestBid;
    private PriceLevel bestOffer;
    private Map<OrderID, Order> orderMap;
}
```

- **Enhancement:** Changed `List<Order>` to `DoublyLinkedList<Order>` to support O(1) deletion.



![Figure 14 Place, match, and cancel an order in O(1)](https://bytebytego.com/images/courses/system-design-interview/stock-exchange/figure-14-place-match-and-cancel-an-order-in-o1-GG4SP5FK.svg)

---

#### **Operation Breakdown with Optimized Order Book**

1. **Placing a New Order:**
   - **Action:** Add the order to the tail of the `DoublyLinkedList`.
   - **Time Complexity:** O(1).
  
2. **Matching an Order:**
   - **Action:** Remove the order from the head of the `DoublyLinkedList`.
   - **Time Complexity:** O(1).
  
3. **Canceling an Order:**
   - **Action:** Use `orderMap` to locate the order and remove it directly from the `DoublyLinkedList`.
   - **Time Complexity:** O(1).

**Figure 14:** Visualizes how placing, matching, and canceling orders achieve O(1) time complexity with the optimized data structure.

---

#### **Integration with Market Data Processor**

- **Usage:** The order book data structure is extensively utilized by the **Market Data Processor** to reconstruct:
  - **L1 Data:** Best bid and ask prices.
  - **L2 Data:** Multiple price levels beyond the best bid and ask.
  - **L3 Data:** Full order book with all queued quantities.
  
---

### Key Takeaways

- **Efficient Data Structures:** Utilizing doubly-linked lists and hash maps ensures that critical operations on the order book are performed in constant time, meeting the high-performance requirements of the exchange system.
  
- **Real-Time Processing:** An optimized order book allows the matching engine to handle large volumes of orders rapidly, maintaining the integrity and responsiveness of the trading platform.
  
- **Scalability and Reliability:** The designed data structures support scalability, enabling the system to handle increasing numbers of orders and maintaining consistent performance.
  
- **Market Data Integration:** A well-structured order book facilitates accurate and timely market data generation, essential for real-time analytics and informed trading decisions.
  

By implementing an optimized order book structure, the stock exchange system ensures high efficiency, low latency, and robust performance, which are crucial for handling the demanding requirements of real-time trading environments.







### Step 3: Design Deep Dive

This section explores the advanced architectural strategies employed by modern stock exchanges to achieve ultra-low latency and high performance. It highlights how exchanges have evolved from distributed server architectures to highly optimized single-server designs, leveraging specialized techniques to minimize latency and ensure stability.

---

#### **Performance Considerations**

- **Latency Importance:**
  - **Low Average Latency:** Ensures rapid order processing.
  - **Stable Latency:** Maintains consistent performance, measured by the 99th percentile latency.

- **Latency Breakdown:**
  - **Formula:** 
    \[
    \text{Latency} = \sum \text{executionTimeAlongCriticalPath}
    \]
  - **Reduction Strategies:**
    1. **Decrease Critical Path Tasks:**
       - Minimize the number of components involved in the critical trading path.
       - **Critical Path:** `gateway -> order manager -> sequencer -> matching engine`
       - **Optimization:** Remove non-essential tasks (e.g., logging) from the critical path.
    2. **Shorten Task Execution Time:**
       - **Eliminate Network and Disk Usage:** Reduce or remove dependencies on network calls and disk I/O.
       - **Optimize Task Execution:** Streamline code to execute tasks faster.

---

#### **From Distributed to Single-Server Architecture**

- **Initial High-Level Design Issues:**
  - **Distributed Components:** Separate servers introduce cumulative network latency (~500 microseconds per hop).
  - **Disk Access:** Sequencer persists events to disk, adding tens of milliseconds to latency.

- **Modern Single-Server Design:**
  - **Consolidation:** Place all critical components on a single server to eliminate network hops.
  - ![Figure 15 A low latency single server exchange design](https://bytebytego.com/images/courses/system-design-interview/stock-exchange/figure-15-a-low-latency-single-server-exchange-design-T5ZFOSZB.svg)
  - **Shared Memory Communication:**
    - **Technique:** Use `mmap` to map files into memory for inter-component communication.
    - **Benefit:** Achieves sub-microsecond message passing without network or disk delays.
  
- **Illustration:**
  - **Figure 15:** Depicts a low-latency design with all critical components residing on a single server.

---

#### **Key Design Elements**

1. **Application Loops:**
   - **Concept:** Continuous polling for tasks within a while loop.
   - **Purpose:** Execute mission-critical tasks with predictable, low latency.
   - **Implementation:**
     - **Single-Threaded:** Each application loop runs on a dedicated thread.
     - **CPU Pinning:** Threads are pinned to specific CPU cores to:
       - **Prevent Context Switching:** Ensures the thread has exclusive access to its CPU core.
       - **Avoid Lock Contention:** Single-threaded access eliminates the need for locks, reducing latency.
   - ![Figure 16 Application loop thread in Order Manager](https://bytebytego.com/images/courses/system-design-interview/stock-exchange/figure-16-application-loop-thread-in-order-manager-F76ALFG4.svg)
   - **Example:**
     - **Order Manager Loop:** Pinned to CPU 1, handles order processing without interruptions.
   
   - **Trade-offs:**
     - **Complex Coding:** Requires careful task management to prevent blocking the loop.
     - **Predictable Execution:** Ensures consistent latency by avoiding long task executions.
   
   - **Illustration:**
     - **Figure 16:** Shows an application loop thread in the Order Manager, pinned to a specific CPU core.
   
2. **Memory-Mapped Files (`mmap`):**
   - **Definition:** A POSIX system call that maps a file into a process's memory space.
   - **Usage in Exchange Design:**
     - **Shared Memory Communication:** Facilitates high-speed data exchange between components.
     - **Memory-Backed Storage:** Utilize `/dev/shm` (a memory-backed filesystem) to avoid disk I/O.
     - **Event Store Implementation:** Acts as a fast, in-memory message bus for orders and executions.
   - **Benefits:**
     - **Eliminates Network Hops:** Components communicate within the same server memory space.
     - **Sub-Microsecond Latency:** Achieves near-instantaneous message passing.
     - **Efficient Event Sourcing:** Supports reliable and fast state management through in-memory event logs.

---

#### **Optimizing the Critical Path**

- **Critical Path Components on Single Server:**
  - **Gateway:** Receives and forwards orders.
  - **Order Manager:** Handles risk checks and fund verification.
  - **Sequencer:** Assigns sequence IDs and manages event storage.
  - **Matching Engine:** Executes order matching and generates executions.

- **Latency Reduction Techniques:**
  - **Minimized Network Calls:** By colocating components, network-induced delays are removed.
  - **In-Memory Operations:** Use of `mmap` and shared memory ensures rapid data access and transfer.
  - **Single-Threaded Loops:** Dedicated threads prevent latency spikes caused by multi-threaded contention.

---

#### **Integration and Scalability**

- **Event Sourcing Paradigm:**
  - **State Management:** Maintains system state through a continuous log of events, enabling fast recovery and replay.
  - **Microservices within Server:** Allows for modular, low-latency services operating cohesively on a single server.

- **Scalability Considerations:**
  - **Single Server Limits:** While reducing latency, this approach may face scalability constraints.
  - **Future Enhancements:** Potential for multi-server optimizations while maintaining low latency through advanced inter-process communication techniques.

---

### **Key Takeaways**

- **Single-Server Optimization:** Consolidating critical components on one server drastically reduces latency by eliminating network and disk access delays.
- **Efficient Communication:** Leveraging `mmap` for shared memory ensures rapid data exchange between components.
- **Predictable Performance:** Single-threaded, CPU-pinned application loops eliminate context switching and lock contention, ensuring stable low-latency operation.
- **Complexity Trade-offs:** Achieving ultra-low latency requires sophisticated design choices, such as careful task management and memory mapping, increasing implementation complexity.
- **Event Sourcing:** Utilizing in-memory event stores supports fast state management and reliable system recovery, essential for high-performance trading environments.

By adopting these advanced architectural strategies, modern stock exchanges achieve the necessary performance and reliability to handle high-frequency trading demands, ensuring that latency remains minimal and stable even under intense trading conditions.





